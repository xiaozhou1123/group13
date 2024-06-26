# 1. 功能测试

## 1.1 正常功能测试

1. ### **功能1：选择要计算的函数**

   - 测试步骤：选择不同的函数（sin/cos/arcsin/arccos/arctan）
   - 预期结果：可以成功选择各种函数。

2. ### **功能2：选择输入的形式**

   - 测试步骤：选择输入的形式（deg/rad）
   - 预期结果：可以成功选择角度制或弧度制。

3. ### **功能3：输入值**

   - 测试步骤：输入要计算的值，支持数字、π（pi）以及常规表达式。
   - 预期结果：可以成功输入各种类型的值。

4. ### **功能4：计算结果**

   - 测试步骤：点击计算按钮或按回车键进行计算。
   - 预期结果：能够正确计算并显示结果，包括函数名、输入值、计算结果。

## 1.2 异常功能测试

1. ### **功能1：空输入**

   - 测试步骤：不输入任何值，直接点击计算按钮。
   - 预期结果：弹出错误消息提示用户输入一个值。

2. ### **功能2：角度制下输入π**

   - 测试步骤：选择角度制，输入 "pi"。
   - 预期结果：弹出错误消息提示角度制下不允许输入π。

3. ### **功能3：无效输入**

   - 测试步骤：输入无效的表达式，例如输入 "2 + * pi"。
   - 预期结果：弹出错误消息提示输入的值无效，请重新输入。

4. ### **功能4：选择弧度制下输入无效表达式**

   - 测试步骤：选择弧度制，输入无效的表达式，例如输入 "2 * *"。
   - 预期结果：弹出错误消息提示输入的值无效，请重新输入。

5. ### **功能5：输入包含括号的表达式**

   - 测试步骤：输入包含括号的表达式，例如输入 "(2 + 3) * 2"。
   - 预期结果：能够成功计算包含括号的表达式，并正确显示计算结果。

6. ### **功能6：选择角度制下输入非数值字符**

   - 测试步骤：选择角度制，输入非数值字符，例如输入 "abc"。
   - 预期结果：弹出错误消息提示输入的值无效，请重新输入。

7. ### **功能7：选择弧度制下输入非数值字符**

   - 测试步骤：选择弧度制，输入非数值字符，例如输入 "xyz"。
   - 预期结果：弹出错误消息提示输入的值无效，请重新输入。

8. ### **功能8：输入包含除数为零的表达式**

   - 测试步骤：输入包含除数为零的表达式，例如输入 "1 / 0"。
   - 预期结果：弹出错误消息提示除数不能为零。

9. ### **功能9：输入表达式中的非法字符**

   - 测试步骤：输入包含非法字符的表达式，例如输入 "!@#$%"。
   - 预期结果：弹出错误消息提示输入的值无效，请重新输入。

   

# 2. 界面测试

1. ## **菜单功能**

   - 测试步骤：点击菜单中的使用说明。
   - 预期结果：弹出使用说明对话框，显示应用程序的使用说明。

2. ## **窗口缩放**

   - 测试步骤：尝试拖动窗口边缘调整窗口大小。
   - 预期结果：窗口不可缩放。

# 3. 其他测试

1. 跨语言测试
   - 测试步骤：调用使用matlab语言编写的三角函数，并运行应用程序。
   - 预期结果：应用程序能够正常运行并保持一致的功能。