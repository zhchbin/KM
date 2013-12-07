ScrollLabels = {
	labels : new Array(),
	lastScrollTop : -1,
	speed : 3,
	 
	addToContentPage : function() {
		var labelsBox = $('<div id="qstl_box"></div>').appendTo($('body'));
		labelsBox.css('background-color', '#111'); 
		labelsBox.css('color', '#eee');
		labelsBox.hover(function() {
			labelsBox.attr('class', 'end');
		}, function() {
			labelsBox.attr('class', 'begin');
		});
		labelsBoxWrapper = $('<div id="qstl-wrapper"></div>').appendTo(labelsBox);

		var helpImgSrc = chrome.extension.getURL("images/help.png");
		var helpOnImgSrc = chrome.extension.getURL("images/help_on.png");
		var help = $('<div id="qstl-box-help" style="background-image: url(' + helpImgSrc + ');"></div>').appendTo(labelsBoxWrapper);
		help.hover(function() {
			help.css('background-image', 'url(' + helpOnImgSrc + ')');
		}, function() {
			help.css('background-image', 'url(' + helpImgSrc + ')');
		});
		help.click(function() {
			var optionsURL = chrome.extension.getURL("options.html");
			window.open(optionsURL);
		});

		var info = $('<div id="qstl-box-info">QuickScrollToLabel</div>').appendTo(labelsBoxWrapper);
		info.click(function() {
			var time = $(window).scrollTop() / ScrollLabels.speed;
			$('html,body').animate({scrollTop: 0}, time);
		});
		$('<div id="qstl-box-tidbits"></div>').appendTo(labelsBoxWrapper);
		var bottom = $('<div id="qstl-box-bottom">Back</div>').appendTo(labelsBoxWrapper);
		bottom.click(function(){
			if (ScrollLabels.lastScrollTop == -1)
				return;
			var time = Math.abs($(window).scrollTop() - ScrollLabels.lastScrollTop) / ScrollLabels.speed;
			$('html,body').animate({scrollTop: ScrollLabels.lastScrollTop}, time);
		});
	},

	addLabelInSelection : function() {
		var element = document.createElement('span');
		element.className = "scrollLabel";
		var sel = window.getSelection() || document.getSelection() || (document.selection ? document.selection.createRange() : null);
		if (sel.rangeCount) {
			var range = sel.getRangeAt(0).cloneRange();
			var str = sel.toString();
			if (str.length <= 0)
				return;
			range.surroundContents(element);
			sel.removeAllRanges();
			sel.addRange(range);
			sel.removeAllRanges();

			ScrollLabels.labels.push($(window).scrollTop());
			var label = $('<div class="qstl-box-tidbit"></div>').appendTo($('#qstl-box-tidbits'));
			label.html(str);
			label.click(function() {
				ScrollLabels.lastScrollTop = $(window).scrollTop();
				var index = $('.qstl-box-tidbit').index(this);
				var time = Math.abs($(window).scrollTop() - ScrollLabels.labels[index]) / ScrollLabels.speed;
				console.log(time);
				// $(ScrollLabels.labels[index]).ScrollTo();
				$('html,body').stop().animate({scrollTop: ScrollLabels.labels[index]}, time);
			});

		}

	}
};

$(function() {
	chrome.extension.onMessage.addListener(function(request, sender, sendResponse) {
		if (request.command == "addLabel") {
			ScrollLabels.addLabelInSelection();
		}
	});
});

ScrollLabels.addToContentPage(); // Add icon to the body element
chrome.extension.sendRequest({
	method : "getSettings"
}, function(settings) {
	$('#qstl_box').css('bottom', settings.bottom + 'px');
	$('#qstl_box').css('right', settings.right + 'px');
	$('#qstl_box').css('width', settings.width + 'px');
	$('#qstl_box').attr('class', 'begin_' + settings.opacity * 10);
	$('#qstl_box').unbind('hover').hover(function() {
		$('#qstl_box').attr('class', 'end');
	}, function() {
		$('#qstl_box').attr('class', 'begin_' + settings.opacity * 10);
	});
	$('#qstl_box').css('background-color', settings.bgColor); 
	$('#qstl_box').css('color', settings.fontColor);
	ScrollLabels.speed = settings.speed;
});
