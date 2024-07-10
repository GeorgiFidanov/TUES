const {
  CustomEventHandler,
} = require("../implementation/EventHandler");

describe("CustomEventHandler", () => {
  let eventHandler;

  beforeEach(() => {
    eventHandler = new CustomEventHandler();
  });

  test("Subscribe to an event and emit it", () => {
    let receivedData = null;

    eventHandler.subscribe("testEvent", (data) => {
      receivedData = data;
    });

    const testData = "Test Data";
    eventHandler.emit("testEvent", testData);

    expect(receivedData).toBe(testData);
  });

  test("Unsubscribe from an event and not receive further emissions", () => {
    let callbackCalled = false;

    const callback = () => {
      callbackCalled = true;
    };

    eventHandler.subscribe("testEvent", callback);
    eventHandler.unsubscribe("testEvent", callback);

    eventHandler.emit("testEvent", "Test Data");

    expect(callbackCalled).toBe.false;
  });

  test("Handle multiple subscribers to an event", () => {
    let receivedData1 = null;
    let receivedData2 = null;

    eventHandler.subscribe("testEvent", (data) => {
      receivedData1 = data;
    });

    eventHandler.subscribe("testEvent", (data) => {
      receivedData2 = data;
    });

    const testData = "Test Data";
    eventHandler.emit("testEvent", testData);

    expect(receivedData1).toBe(testData);
    expect(receivedData2).toBe(testData);
  });

  test("Handle multiple events and emissions", () => {
    let receivedDataEvent1 = null;
    let receivedDataEvent2 = null;

    eventHandler.subscribe("event1", (data) => {
      receivedDataEvent1 = data;
    });

    eventHandler.subscribe("event2", (data) => {
      receivedDataEvent2 = data;
    });

    const testDataEvent1 = "Data for Event 1";
    const testDataEvent2 = "Data for Event 2";

    eventHandler.emit("event1", testDataEvent1);
    eventHandler.emit("event2", testDataEvent2);

    expect(receivedDataEvent1).toBe(testDataEvent1);
    expect(receivedDataEvent2).toBe(testDataEvent2);
  });

  test("Handle once-only event listeners", () => {
    let callback1Count = 0;
    const callback1 = () => {
      callback1Count++;
    };

    eventHandler.subscribe("onceEvent", callback1, { once: true });
    eventHandler.subscribe("onceEvent", () => {});

    eventHandler.emit("onceEvent");
    eventHandler.emit("onceEvent");

    expect(callback1Count).toBe(1);
  });

  test("Allow event handlers to return values", () => {
    eventHandler.subscribe("returnValueEvent", () => {
      return "Async Result";
    });

    eventHandler.subscribe("returnValueEvent", () => {
      return "Sync Result";
    });

    const results = eventHandler.emit("returnValueEvent");

    expect(results).toEqual(["Async Result", "Sync Result"]);
  });
});
