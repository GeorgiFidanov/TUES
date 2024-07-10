# Reflex app
import reflex as rx

class MyApp(rx.App):
    async def fetch_data(self):
        # Send GET request to Flask app
        response = await rx.fetch('http://localhost:5000/api')
        
        # Update state with received data
        self.state['data'] = await response.json()

    def build(self):
        # Use state in UI
        return rx.heading([
            rx.text('Data from Flask:'),
        ])


if __name__ == '__main__':
    from threading import Thread


    # Create Flask app
    app = MyApp()
    app.compile()
    app.build()




