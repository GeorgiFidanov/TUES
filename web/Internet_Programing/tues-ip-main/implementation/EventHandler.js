class CustomEventHandler {
  constructor() {
    this.events = {};
  }

  // Subscribe to an event with optional options
  subscribe(eventName, callback, options = {}) {
    // Create an array for the event if it doesn't exist
    if (!this.events[eventName]) {
      this.events[eventName] = [];
    }

    // Add the callback along with its options
    const eventCallback = {
      callback: callback,
      options: {
        once: options.once || false,
        priority: options.priority || 0,
      },
    };

    // Add the callback to the event's array
    this.events[eventName].push(eventCallback);

    // Sort callbacks by priority
    this.events[eventName].sort((a, b) => b.options.priority - a.options.priority);
  }

  // Unsubscribe from an event
  unsubscribe(eventName, callback) {
    // If the event exists
    if (this.events[eventName]) {
      // Use Array.prototype.filter to remove the specified callback
      this.events[eventName] = this.events[eventName].filter((eventCallback) => {
        return eventCallback.callback !== callback;
      });
    }
  }

  emit(eventName, data, context) {
    const results = [];

    // If the event exists, loop through the callbacks and call them
    if (this.events[eventName]) {
      // Iterate through the callbacks for the specified event
      for (const eventCallback of this.events[eventName]) {
        // Call the callback function with the provided data and context
        const result = eventCallback.callback(data, context);

        // Collect results from callbacks
        results.push(result);

        // If the callback is a "once" callback, unsubscribe it
        if (eventCallback.options.once) {
          this.unsubscribe(eventName, eventCallback.callback);
        }
      }
    }

    return results;
  }
}

module.exports.CustomEventHandler = CustomEventHandler;
