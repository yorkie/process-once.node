'use strict';

const once = require('./');
const assert = require('assert');
var count = 0;

once(function() {
  console.log('pass');
  count += 1;
});

once(function() {
  console.log('this function would not be get called');
  count += 1;
});

assert.deepEqual(count, 1, 'the count should be equal to 1');
