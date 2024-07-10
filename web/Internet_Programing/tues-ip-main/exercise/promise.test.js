const { PromiseImplementation } = require("../implementation/Promise");
//const PromiseImplementation = Promise;
describe("Custom Promise Implementation", () => {
  // Test cases for resolving promises
  test("Resolving a promise with a value", (done) => {
    new PromiseImplementation((resolve) => {
      resolve("Resolved value");
    }).then((result) => {
      expect(result).toBe("Resolved value");
      done();
    });
  });

  test("Resolving a promise with undefined", (done) => {
    new PromiseImplementation((resolve) => {
      resolve(undefined);
    }).then((result) => {
      expect(result).toBe(undefined);
      done();
    });
  });

  test("Calling then multiple times on a single promise", (done) => {
    const promise = new PromiseImplementation((resolve) => {
      setTimeout(() => {
        resolve("Async resolved");
      }, 100);
    });

    promise.then((result) => {
      expect(result).toBe("Async resolved");
    });

    promise.then((result) => {
      expect(result).toBe("Async resolved");
      done();
    });
  });

  // Test cases for rejecting promises
  test("Rejecting a promise with an error message", (done) => {
    new PromiseImplementation((resolve, reject) => {
      reject("Error message");
    }).catch((error) => {
      expect(error).toBe("Error message");
      done();
    });
  });

  // Test cases for chaining multiple then and catch calls
  test("Chaining multiple then calls", (done) => {
    new PromiseImplementation((resolve) => {
      resolve(1);
    })
      .then((result) => {
        expect(result).toBe(1);
        return result + 2;
      })
      .then((result) => {
        expect(result).toBe(3);
        return result * 2;
      })
      .then((result) => {
        expect(result).toBe(6);
        done();
      });
  });

  // Test cases for asynchronous behavior
  test("Resolving asynchronously", (done) => {
    new PromiseImplementation((resolve) => {
      setTimeout(() => {
        resolve("Async resolved");
      }, 100);
    }).then((result) => {
      expect(result).toBe("Async resolved");
      done();
    });
  });

  test("Rejecting asynchronously", (done) => {
    new PromiseImplementation((resolve, reject) => {
      setTimeout(() => {
        reject("Async error");
      }, 100);
    }).catch((error) => {
      expect(error).toBe("Async error");
      done();
    });
  });

  // Testing then and catch with asynchronous behavior
  test("Chaining then and catch with asynchronous behavior", (done) => {
    const errHandler = jest.fn();
    new PromiseImplementation((resolve, reject) => {
      setTimeout(() => {
        resolve("Async resolved");
      }, 100);
    })
      .then((result) => {
        expect(result).toBe("Async resolved");
        return "Next async";
      })
      .catch(errHandler)
      .then((result) => {
        expect(result).toBe("Next async");
        done();
      });
    expect(errHandler).not.toHaveBeenCalled();
  });
});

describe("Advanced tests", () => {
  // Test cases for Promise.all
  test("Promise.all with an array of resolved promises", (done) => {
    const promises = [
      PromiseImplementation.resolve(1),
      PromiseImplementation.resolve(2),
      PromiseImplementation.resolve(3),
    ];

    PromiseImplementation.all(promises).then((result) => {
      expect(result).toEqual([1, 2, 3]);
      done();
    });
  });

  test("Promise.all with an array of mixed promises", (done) => {
    const promises = [
      PromiseImplementation.resolve(1),
      PromiseImplementation.reject("Error"),
      PromiseImplementation.resolve(3),
    ];

    PromiseImplementation.all(promises).catch((error) => {
      expect(error).toBe("Error");
      done();
    });
  });

  // Test cases for Promise.race
  test("Promise.race with resolved values", (done) => {
    const promises = [
      PromiseImplementation.resolve(1).then(() =>
        PromiseImplementation.resolve("fast")
      ),
      PromiseImplementation.resolve(2).then(() =>
        PromiseImplementation.resolve("winner")
      ),
    ];

    PromiseImplementation.race(promises).then((result) => {
      expect(result).toBe("fast");
      done();
    });
  });

  test("Promise.race with a rejected promise", (done) => {
    const promises = [
      PromiseImplementation.resolve(1).then(() =>
        PromiseImplementation.reject("Error")
      ),
      PromiseImplementation.resolve(2).then(() =>
        PromiseImplementation.resolve("winner")
      ),
    ];

    PromiseImplementation.race(promises).catch((error) => {
      expect(error).toBe("Error");
      done();
    });
  });
});
