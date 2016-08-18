process-once.node
-----------------------------

The `pthread_once(3)` binding to the Node.js community.

### Installation

```sh
$ npm install process-once.node --save
```

### Example

```es6
const once = require('process-once.node');
once(() => {
  // run this function once in this process
});
```

### Purposes

1. this package is for learning how `pthread_once` works.
2. this package is experimental and could be replaced with simple 
   call function directly.

### License

MIT
