from Downloads.templates import template
import reflex as rx

@template(route="/", title="Home", image="/github.svg")
def index():
    return rx.link(
            rx.text("Mlqko"),
            href="http://localhost:3000/mlqko",
        )
