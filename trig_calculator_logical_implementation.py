import math

# 计算sin函数的近似值
def my_sin(x):
    result = 0
    for n in range(10):  # 假设使用10项泰勒级数展开
        result += ((-1) ** n) * (x ** (2 * n + 1)) / math.factorial(2 * n + 1)
    return result

# 计算cos函数的近似值
def my_cos(x):
    result = 0
    for n in range(10):  # 假设使用10项泰勒级数展开
        result += ((-1) ** n) * (x ** (2 * n)) / math.factorial(2 * n)
    return result

# 计算arcsin函数的近似值
def my_arcsin(x):
    result = 0
    for n in range(10):  # 假设使用10项泰勒级数展开
        result += math.factorial(2 * n) / ((4 ** n) * (math.factorial(n) ** 2) * (2 * n + 1)) * (x ** (2 * n + 1))
    return result

# 计算arccos函数的近似值
def my_arccos(x):
    return math.pi / 2 - my_arcsin(x)

# 计算arctan函数的近似值
def my_arctan(x):
    result = 0
    for n in range(10):  # 假设使用10项泰勒级数展开
        result += ((-1) ** n) * (x ** (2 * n + 1)) / (2 * n + 1)
    return result

def get_function_choice():
    while True:
        choice = input("请选择要计算的函数（sin/cos/arcsin/arccos/arctan），输入'exit'退出程序：").lower()
        if choice in ['sin', 'cos', 'arcsin', 'arccos', 'arctan']:
            return choice
        elif choice == 'exit':
            return 'exit'
        else:
            print("无效的选择，请重新输入。")

def get_input_mode():
    while True:
        mode = input("请选择输入的形式（deg/rad），输入'exit'退出程序：").lower()
        if mode in ['deg', 'rad']:
            return mode
        elif mode == 'exit':
            return 'exit'
        else:
            print("无效的输入形式，请重新输入。")

def get_angle():
    while True:
        angle_str = input("请输入{}值，输入'exit'退出程序：".format("角度" if mode == 'deg' else "弧度"))
        if angle_str == 'exit':
            return 'exit'

        try:
            angle = float(angle_str)
            return angle
        except ValueError:
            print("错误：输入无效，请重新输入。")

# 与用户交互的部分
print("欢迎使用三角函数计算器！")
while True:
    choice = get_function_choice()
    if choice == 'exit':
        print("谢谢使用！")
        break

    mode = get_input_mode()
    if mode == 'exit':
        print("谢谢使用！")
        break

    angle = get_angle()
    if angle == 'exit':
        print("谢谢使用！")
        break

    if mode == 'deg':
        angle_rad = math.radians(angle)  # 将角度转换为弧度
    else:
        angle_rad = angle

    if choice == 'sin':
        result = my_sin(angle_rad)
    elif choice == 'cos':
        result = my_cos(angle_rad)
    elif choice == 'arcsin':
        result = my_arcsin(angle_rad)
        angle = math.degrees(result)  # 将弧度转换为角度
    elif choice == 'arccos':
        result = my_arccos(angle_rad)
        angle = math.degrees(result)  # 将弧度转换为角度
    elif choice == 'arctan':
        result = my_arctan(angle_rad)
        angle = math.degrees(result)  # 将弧度转换为角度

    print("{}({}°) ≈ {}".format(choice, angle, result))