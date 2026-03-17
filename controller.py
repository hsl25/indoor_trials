import tkinter as tk
import serial

# ---------- Bluetooth Serial ----------
ser = serial.Serial("COM4", 9600)

def send_command(cmd):
    ser.write(cmd.encode())
    print("Sent:", cmd)


# ---------- GUI ----------
root = tk.Tk()
root.title("Rover Controller")
root.geometry("400x400")
root.configure(bg="#1e1e1e")

canvas = tk.Canvas(root, width=300, height=300, bg="#1e1e1e", highlightthickness=0)
canvas.pack(expand=True)

button_color = "#3aa6ff"
hover_color = "#6cc0ff"


def create_triangle(points, command):
    tri = canvas.create_polygon(points, fill=button_color, outline="white", width=2)

    def on_enter(e):
        canvas.itemconfig(tri, fill=hover_color)

    def on_leave(e):
        canvas.itemconfig(tri, fill=button_color)

    def on_click(e):
        send_command(command)

    canvas.tag_bind(tri, "<Enter>", on_enter)
    canvas.tag_bind(tri, "<Leave>", on_leave)
    canvas.tag_bind(tri, "<Button-1>", on_click)


# Forward
create_triangle(
    [150, 40, 110, 100, 190, 100],
    "F"
)

# Backward
create_triangle(
    [150, 260, 110, 200, 190, 200],
    "B"
)

# Left
create_triangle(
    [40, 150, 100, 110, 100, 190],
    "L"
)

# Right
create_triangle(
    [260, 150, 200, 110, 200, 190],
    "R"
)

# Center label
canvas.create_text(
    150, 150,
    text="ROVER",
    fill="white",
    font=("Helvetica", 16, "bold")
)

root.mainloop()