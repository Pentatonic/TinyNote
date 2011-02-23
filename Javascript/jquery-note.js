/*
	jQuery Notes
*/


// append row to table body, add row
$('#tabPrinter > tbody:last').append('<tr><td> wow </td></tr>');


// remove class, css
$('#div1').removeClass();


// add class, css
$('#div1').addClass('menu3_selected');


// mouse click, fisrt row
var fRow = $('#tabPrinter > tbody > tr:first');
if (fRow.length) {
	fRow.click();
}


// empty table, body, empty DOM element
$('#tabPrinter > tbody:last').empty();

// ajax, post
$.ajax({
	url:'../servlet/Printer',
	type:'post',
	dataType:'json',
	data: 'op=get',
	async: false, 
	success: function(json) {
		if (json.printer) {
			alert('Success, ther is printer!');
		}
	}		
});

