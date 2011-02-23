
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

