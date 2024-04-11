import math


def trig_calculator(angle_degrees):
    """
    Calculate sine, cosine, tangent, arcsine, arccosine, and arctangent
    of the input angle in degrees.

    Args:
        angle_degrees (float): The angle in degrees.

    Returns:
        tuple: A tuple containing the sine, cosine, tangent, arcsine, arccosine,
               and arctangent values.
    """
    angle_radians = math.radians(angle_degrees)
    sin_value = math.sin(angle_radians)
    cos_value = math.cos(angle_radians)
    tan_value = math.tan(angle_radians)

    # Calculate arcsine, arccosine, and arctangent only if values are within the domain
    if -1 <= sin_value <= 1:
        arcsin_value = math.degrees(math.asin(sin_value))
    else:
        arcsin_value = None

    if -1 <= cos_value <= 1:
        arccos_value = math.degrees(math.acos(cos_value))
    else:
        arccos_value = None

    if tan_value != math.inf and tan_value != -math.inf:
        arctan_value = math.degrees(math.atan(tan_value))
    else:
        arctan_value = None

    return sin_value, cos_value, tan_value, arcsin_value, arccos_value, arctan_value


def get_user_input():
    """
    Get user input for the angle in degrees.

    Returns:
        float: The angle in degrees entered by the user.
    """
    while True:
        try:
            angle_degrees = float(input("Enter the angle in degrees: "))
            return angle_degrees
        except ValueError:
            print("Invalid input. Please enter a valid number.")


def main():
    """
    Main function to run the trigonometric calculator.
    """
    print("Welcome to Trigonometric Calculator!")
    while True:
        angle_degrees = get_user_input()
        sin_value, cos_value, tan_value, arcsin_value, arccos_value, arctan_value = trig_calculator(angle_degrees)
        print(f"Sine: {sin_value:.4f}")
        print(f"Cosine: {cos_value:.4f}")
        print(f"Tangent: {tan_value:.4f}")
        if arcsin_value is not None:
            print(f"Arcsine: {arcsin_value:.4f}")
        else:
            print("Arcsine: Undefined")
        if arccos_value is not None:
            print(f"Arccosine: {arccos_value:.4f}")
        else:
            print("Arccosine: Undefined")
        if arctan_value is not None:
            print(f"Arctangent: {arctan_value:.4f}")
        else:
            print("Arctangent: Undefined")

        choice = input("Do you want to calculate again? (yes/no): ").lower()
        if choice != "yes":
            print("Thank you for using Trigonometric Calculator!")
            break


if __name__ == "__main__":
    main()
