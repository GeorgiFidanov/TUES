from Downloads.templates import template
from Downloads.components.navbar import *
from Downloads.components.header import *
import reflex as rx


@template(route="/mlqko", title="Mlqko")
def mlqko() -> rx.Component:
    # Return some data
    return rx.container(
        navbar(),
        rx.divider(),
        header(),
        rx.divider(),
    )