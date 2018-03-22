const promise = new Promise((resolve, reject) => {
    resolve(0);
    //reject('n/a');
});

promise.then((value) => {
    console.log('resolved1: ' + value);
    throw 'ooo';
    return value + 1;
}, (reason) => {
    console.log('rejected1: ' + reason);
}).then((value) => {
    console.log('resolved2: ' + value);
    return value + 1;
}, (reason) => {
    console.log('rejected2: ' + reason);
    //throw 'ppp';
}).catch((e) => {
    console.log('catch: ' + e);
});






Promise.resolve()
  .then( () => {
    // Makes .then() return a rejected promise
    throw 'Oh no!';
  })
  .catch( reason => {
    console.error( 'onRejected function called: ', reason );
  })
  .then( () => {
    console.log( "I am always called even if the prior then's promise rejects" );
  });








function resolveLater(resolve, reject) {
  setTimeout(function () {
    resolve(10);
  }, 1000);
}
function rejectLater(resolve, reject) {
  setTimeout(function () {
    reject(20);
  }, 1000);
}

var p1 = Promise.resolve('foo');
var p2 = p1.then(function() {
  // Return promise here, that will be resolved to 10 after 1 second
  return new Promise(resolveLater);
});
p2.then(function(v) {
  console.log('resolved', v);  // "resolved", 10
}, function(e) {
  // not called
  console.log('rejected', e);
});

var p3 = p1.then(function() {
  // Return promise here, that will be rejected with 20 after 1 second
  return new Promise(rejectLater);
});
p3.then(function(v) {
  // not called
  console.log('resolved', v);
}, function(e) {
  console.log('rejected', e); // "rejected", 20
});
