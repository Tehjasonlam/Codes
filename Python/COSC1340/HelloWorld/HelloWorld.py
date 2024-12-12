import turtle

# Create a turtle object
t = turtle.Turtle()

# Move the turtle to the starting point
t.penup()
t.goto(-50, 0)
t.pendown()

# Draw the face
t.circle(50)

# Draw the eyes
t.penup()
t.goto(-25, 30)
t.pendown()
t.dot(20, 'white')
t.penup()
t.goto(25, 30)
t.pendown()
t.dot(20, 'white')
t.penup()

# Draw the pupils
t.goto(-25, 35)
t.pendown()
t.dot(10, 'black')
t.penup()
t.goto(25, 35)
t.pendown()
t.dot(10, 'black')
t.penup()

# Draw the mouth
t.goto(0, 10)
t.pendown()
t.circle(20, 180)

# Draw the horns
t.penup()
t.goto(-45, 75)
t.pendown()
t.left(90)
t.forward(30)
t.left(120)
t.forward(30)
t.penup()
t.goto(45, 75)
t.pendown()
t.right(240)
t.forward(30)
t.right(120)
t.forward(30)

# Hide the turtle
t.hideturtle()

# Keep the window open until it is closed manually
turtle.done()
