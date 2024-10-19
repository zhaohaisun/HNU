这个实验是大家在本课程第一次体验系统级编程，涉及过程，过程控制和信号的相关知识。


1.你需要干什么？
    你需要构建一个简单的类Unix/Linux Shell。基于已经提供的“微Shell”框架tsh.c，完成部分函数和信号处理函数的编写工作。使用sdriver.pl可以评估你所完成的shell的相关功能。

2. 准备工作
  使用命令tar xvf shelab-handout.tar 解压缩文件；
  使用命令 make  去编译和链接一些测试例程；
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  你要实现的重要函数列出如下：
  eval         主例程，用以分析和解释命令行（好消息：该函数原型在教材一第8章8.4节中可以找到！）；
  builtin_cmd  执行bg和fg内置命令；
  waitfg       等待前台作业执行；
  sigchld_handler  响应处理SIGCHILD信号
  sigint_handler   响应处理SIGINT（ctrl-c）信号
  sigtstp_handler  相应处理SIGSTP（ctrl-z）信号

3.注意
  每次修改了tsh.c文件，都需要make它以重新编译。在你的Linux终端中直接运行tsh（./tsh）就可以进入你所编写完成的tiny shell tsh>了。

4. 如何证明你完成了这个实验
   在你的Linux终端运行./tshref  这个已经实现的shell，将其输出结果与你所实现的./tsh 输出结果比较，是否一致。
相关比较命令行，参见shelab-overview文件。

5.请在实验报告体现你解决本实验目标的详细过程，仅仅贴图（图中只有代码）可能会导致“无个人工作，仅仅是复制粘贴”的极低分判定。

Love & Peace！

   
