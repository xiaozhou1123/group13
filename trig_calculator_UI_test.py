import tkinter as tk
from tkinter import messagebox
import math

# todo：测试界面逻辑，最后需要函数替换为自己的
class TrigCalculator(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("三角函数计算器")

        # 创建菜单栏
        menubar = tk.Menu(self)
        self.config(menu=menubar)

        # 创建菜单选项
        help_menu = tk.Menu(menubar, tearoff=0)
        help_menu.add_command(label="使用说明", command=self.show_help)
        menubar.add_cascade(label="帮助", menu=help_menu)

        # 设置函数选择框
        self.label_function = tk.Label(self, text="选择要计算的函数：")
        self.label_function.grid(row=0, column=0, padx=10, pady=5, sticky="w")
        self.function_var = tk.StringVar()
        self.function_var.set("sin")  # 默认选择sin函数
        self.function_option = tk.OptionMenu(self, self.function_var, "sin", "cos", "arcsin", "arccos", "arctan")
        self.function_option.grid(row=0, column=1, padx=10, pady=5)

        # 设置形式选择框
        self.label_angle = tk.Label(self, text="输入的形式：")
        self.label_angle.grid(row=1, column=0, padx=10, pady=5, sticky="w")
        self.angle_var = tk.StringVar()
        self.angle_var.set("deg")  # 默认选择角度形式
        self.angle_option = tk.OptionMenu(self, self.angle_var, "deg", "rad")
        self.angle_option.grid(row=1, column=1, padx=10, pady=5)

        # 设置输入值输入框
        self.label_value = tk.Label(self, text="输入值：")
        self.label_value.grid(row=2, column=0, padx=10, pady=5, sticky="w")
        self.entry_value = tk.Entry(self)
        self.entry_value.grid(row=2, column=1, padx=10, pady=5)

        # 设置计算按钮
        self.button_calculate = tk.Button(self, text="计算", command=self.calculate)
        self.button_calculate.grid(row=3, column=0, columnspan=2, padx=10, pady=5)

    def calculate(self):
        function = self.function_var.get().lower()
        mode = self.angle_var.get().lower()
        value_str = self.entry_value.get()

        # 如果用户选择角度制，则不允许输入 "pi"
        if mode == 'deg' and "pi" in value_str:
            messagebox.showerror("错误", "角度制下不允许输入 pi")
            return

        # 如果用户输入包含 "pi"，则将其替换为 math.pi 的值
        if "pi" in value_str:
            value_str = value_str.replace("pi", str(math.pi))

        try:
            value = eval(value_str)  # 使用 eval 函数计算表达式
        except:
            messagebox.showerror("错误", "输入的值无效，请重新输入")
            return

        if mode == 'deg':  # 根据用户选择的形式进行转换
            value_ori = value
            value = math.radians(value)
        else:
            value_ori = value

        value_display = "{}°".format(value_ori) if mode == 'deg' else "{} rad".format(value_ori)
        result_display = None

        if function == 'sin':
            result = math.sin(value)
        elif function == 'cos':
            result = math.cos(value)
        elif function == 'arcsin':
            result = math.asin(value)
        elif function == 'arccos':
            result = math.acos(value)
        elif function == 'arctan':
            result = math.atan(value)

        if function in ['sin', 'cos']:
            result_display = "{} rad".format(result)
        elif mode == 'deg':
            result_display = "{}°".format(math.degrees(result)) if function in ['arcsin', 'arccos', 'arctan'] else "{} rad".format(result)
        else:
            result_display = "{} rad".format(result)

        if function in ['arcsin', 'arccos', 'arctan']:
            if mode == 'deg':
                result_display = "{}°".format(math.degrees(result))
                value_display = "{}°".format(value_ori)
                convert_result_display = "{} rad".format(result)
            else:
                result_display = "{} rad".format(result)
                value_display = "{} rad".format(value_ori)
                convert_result_display = "{}°".format(math.degrees(result))
        else:
            convert_result_display = "{}°".format(math.degrees(result))

        messagebox.showinfo("计算结果", "{}({}) = {} ≈ {}".format(function, value_display, result_display, convert_result_display))

    def show_help(self):
        messagebox.showinfo("使用说明", "这是一个简单的三角函数计算器，可以计算 sin、cos、arcsin、arccos、arctan 函数的值。\n\n"
                                       "1. 选择要计算的函数。\n"
                                       "2. 选择输入的形式，可以是角度（deg）或弧度（rad）。\n"
                                       "3. 输入要计算的值，可以使用 pi 表示π，例如输入 2 * pi。\n"
                                       "4. 点击计算按钮进行计算。\n\n"
                                       "注意：角度制下不允许输入 pi。")

if __name__ == "__main__":
    app = TrigCalculator()
    app.mainloop()
