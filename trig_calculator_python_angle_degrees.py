import math

# todo: Only input angles are supported

def trig_calculator(angle_degrees):
    """

    Args:
        angle_degrees(float): the angle_degrees from the user's input

    Returns:
        sin_value(float): sin_value
        cos_value(float): cos_value
        tan_value(float): tan_value

    """
    angle_radians = math.radians(angle_degrees)
    sin_value = math.sin(angle_radians)
    cos_value = math.cos(angle_radians)
    tan_value = math.tan(angle_radians)
    return sin_value, cos_value, tan_value

def main():
    """
    interactive input.
    Only supports input of a single angle.
    Check the validity of user input.
    todo: Support radian and Coordinate.

    Returns:

    """
    print("Welcome to Trigonometric Calculator!")
    while True:
        try:
            angle_degrees = float(input("Enter the angle in degrees: "))
            sin_value, cos_value, tan_value = trig_calculator(angle_degrees)
            print("Sine:", sin_value)
            print("Cosine:", cos_value)
            print("Tangent:", tan_value)
        except ValueError:
            print("Invalid input. Please enter a valid number.")

        choice = input("Do you want to calculate again? (yes/no): ").lower()
        if choice != "yes":
            print("Thank you for using Trigonometric Calculator!")
            break

if __name__ == "__main__":
    main()
