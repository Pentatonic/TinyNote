$.fn.truncate = function(options) {  
  
   return this.each(function() {  
  
   });  
};


// A better way
// To avoid namespace collision with $, but still uses the jQuery
// functions by $
(function($){  
 $.fn.truncate = function() {  
  
    return this.each(function() {  
  
    });  
 };  
})(jQuery);