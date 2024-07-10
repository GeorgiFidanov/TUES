class PromiseImplementation {
  constructor(executor) {
    this.state = "pending"; // "pending", "resolved", "rejected"
    this.value = undefined;
    this.error = undefined;
    this.onResolvedCallbacks = [];
    this.onRejectedCallbacks = [];

    const resolve = (value) => {
      if (this.state === "pending") {
        this.state = "resolved";
        this.value = value;
        this.onResolvedCallbacks.forEach((callback) => {
          callback(this.value);
        });
      }
    };

    const reject = (error) => {
      if (this.state === "pending") {
        this.state = "rejected";
        this.error = error;
        this.onRejectedCallbacks.forEach((callback) => {
          callback(this.error);
        });
      }
    };

    try {
      executor(resolve, reject);
    } catch (error) {
      reject(error);
    }
  }

  then(onResolved, onRejected = (error) => error) {
    return new PromiseImplementation((resolve, reject) => {
      if (this.state === "resolved") {
        try {
          const result = onResolved(this.value);
          resolve(result);
        } catch (error) {
          reject(error);
        }
      } else if (this.state === "rejected") {
        try {
          const result = onRejected(this.error);
          resolve(result);
        } catch (error) {
          reject(error);
        }
      } else {
        this.onResolvedCallbacks.push((value) => {
          try {
            const result = onResolved(value);
            resolve(result);
          } catch (error) {
            reject(error);
          }
        });

        this.onRejectedCallbacks.push((error) => {
          try {
            const result = onRejected(error);
            resolve(result);
          } catch (error) {
            reject(error);
          }
        });
      }
    });
  }

  catch(onRejected) {
    return this.then(undefined, onRejected);
  }

  static resolve(value) {
    return new PromiseImplementation((resolve) => {
      resolve(value);
    });
  }

  static reject(error) {
    return new PromiseImplementation((resolve, reject) => {
      reject(error);
    });
  }

  static all(promises) {
    return new PromiseImplementation((resolve, reject) => {
      // Your code here for implementing Promise.all
      const result = [];
      let resCount = 0;
    });
  }

  static race(promises) {
    return new PromiseImplementation((resolve, reject) => {
      // Your code here for implementing Promise.race
    });
  }
}

module.exports.PromiseImplementation = PromiseImplementation;
