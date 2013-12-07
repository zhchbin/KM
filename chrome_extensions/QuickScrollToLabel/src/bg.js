// Send "getSelectedText" message to the seleced tab

chrome.browserAction.onClicked.addListener(function(tab) {
	sendAddLableMessage();
});

function sendAddLableMessage() {
	chrome.tabs.getSelected(null, function(tab) {
		chrome.tabs.sendMessage(tab.id, {
			command : "addLabel"
		}, function(response) {
				
		});
	});
}

chrome.contextMenus.create({
	'title': 'Add label', 
	'type': 'normal',
	'contexts': ['all'],
	'onclick': function() { sendAddLableMessage(); } 
});

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
	}
};

chrome.extension.onRequest.addListener(function(request, sender, sendResponse) {
    if (request.method == "getSettings")
      sendResponse(Settings.readSettings());
    else
      sendResponse({}); // snub them.
});
