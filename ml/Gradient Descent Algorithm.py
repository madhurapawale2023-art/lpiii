
# Gradient Descent Algorithm

def function(x):
    return (x + 3) ** 2

def derivative(x):
    return 2 * (x + 3)

# Initial values
x = 2
learning_rate = 0.1
iterations = 100

# Gradient Descent
for i in range(iterations):
    x = x - learning_rate * derivative(x)

print("Local Minimum Point:", x)
print("Minimum Value:", function(x))
