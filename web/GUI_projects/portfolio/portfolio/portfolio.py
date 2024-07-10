import reflex as rx
from .components.navbar import *
from .components.header import *
from .components.body import *
from .components.footer import *


component_styles = {
    rx.Text: {
        "font-family": "Arial, sans-serif",
        "color": "black",
    },
    rx.Heading: {
        "font-weight": "bold",
        "color": "black",
    },
    rx.Button: {
        "background-color": "black",
        "color": "white",
        "border": "none",
        "padding": "0.5rem 1rem",
        "margin": "0.5rem",
        "border-radius": "0.25rem",
    },
    
    rx.Box: {
   		"padding": "0",
   		"margin": "0",
   		"border-radius": "1rem",
   		"border": "1px solid black",
   		"box-shadow": "0 0 10px 0 rgba(0, 0, 0, 0.2)",
	},

    # Add other component styles as needed
}


# Now you can define your index function and add pages to your app as before
def index():
    return rx.container(
        navbar(),
        rx.divider(),
        header(),
        rx.divider(),
        projects(),
        rx.divider(),
        tech_stack(),
        rx.divider(),
        footer()
    )

app = rx.App(component_styles=component_styles)
app.add_page(index)
app.compile()
