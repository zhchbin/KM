Settings = {
	readSettings : function() {
		var result = new Object();
		result.bottom = localStorage['bottom'] ? localStorage['bottom'] : 0;
		result.right = localStorage['right'] ? localStorage['right'] : 0;
		result.opacity = localStorage['opacity'] ? localStorage['opacity'] : 0.1;
		result.bgColor = localStorage['bgColor'] ? localStorage['bgColor'] : 'rgb(11, 11, 11)';
		result.fontColor = localStorage['fontColor'] ? localStorage['fontColor'] : 'rgb(238, 238, 238)';
		result.width = localStorage['width'] ? localStorage['width'] : 150;
		result.speed = localStorage['speed'] ? localStorage['speed'] : 3;
		return result;
	},
	
	saveSeetings : function() {
		localStorage['bottom'] = $('input[data-role="bottom"]').val();
		localStorage['right'] = $('input[data-role="right"]').val();
		localStorage['opacity'] = $('input[data-role="opacity"]').val();
		localStorage['bgColor'] = $('#bgColor').val();
		localStorage['fontColor'] = $('#fontColor').val();
		localStorage['width'] = $('input[data-role="width"]').val();
		localStorage['speed'] = $('input[data-role="speed"]').val();
	},
	
	resetSettings : function() {
		localStorage.removeItem("bottom");
		localStorage.removeItem("right");
		localStorage.removeItem("opacity");
		localStorage.removeItem("bgColor");
		localStorage.removeItem("fontColor");
		localStorage.removeItem("width");
		localStorage.removeItem("speed");
	}
};

$(function() {
	var colorObject;
	$('#bgColor').focusin(function() {
		colorObject = $(this);
		$('#colorPicker').modal();
	});
	
	$('#fontColor').focusin(function() {
		colorObject = $(this);
		$('#colorPicker').modal();
	});
	
	$('[data-color]').dblclick(function() {
		$('#colorPicker').modal('hide');
		colorObject.val($(this).attr('data-color'));
		var id = colorObject.attr('data-role') + "Label";
		$('#' + id).css('background-color', colorObject.val());
		$('#saveBtn').removeAttr('disabled');
	});
	
	$('.range').change(function() {
		var id = $(this).attr('data-role') + "Label";
		$('#' + id).html($(this).val());
		$('#saveBtn').removeAttr('disabled');
	});
	
	$('#saveBtn').click(function() {
		$('[class="alert alert-success hide"]').fadeOut();
		Settings.saveSeetings();
		$('[class="alert alert-success hide"]').fadeIn();
	});
	
	$('#defaultBtn').click(function() {
		Settings.resetSettings();
		init();
	});
	
	$('#defaultBtn').tooltip();
	
	var init = function() {
		$('input[data-role="bottom"]').attr('max', screen.availHeight - 100);	
		$('input[data-role="right"]').attr('max', screen.availWidth - 280);
		var settings = Settings.readSettings();
		$('input[data-role="bottom"]').val(settings.bottom);
		$('input[data-role="right"]').val(settings.right);
		$('input[data-role="opacity"]').val(settings.opacity);
		$('input[data-role="width"]').val(settings.width);
		$('input[data-role="speed"]').val(settings.speed);
		$('input[data-role="bgColor"]').val(settings.bgColor);
		$('input[data-role="fontColor"]').val(settings.fontColor);
		
		
		$('#bottomLabel').html(settings.bottom);
		$('#rightLabel').html(settings.right);
		$('#opacityLabel').html(settings.opacity);
		$('#widthLabel').html(settings.width);
		$('#speedLabel').html(settings.speed);
		$('#bgColorLabel').css('background-color', settings.bgColor);
		$('#fontColorLabel').css('background-color', settings.fontColor);
	}; 	
	
	init();
}); 
