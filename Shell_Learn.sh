#!/bin/bash
# program:
# 	This program is for me to learn the shell script!
# History:
# 	2017/02/11 MM First release
function printfs(){ #无参数的函数
	echo -n "Hello function of Shell!" #-n参数保证echo完成之后不换行，function函数要放在最前面方便调(Shell的执行是从左到右的！)
}
printfs #注意不需要加上()就可以调用print函数了
function Param_Test(){
	echo "The first param is:$0"
	echo "The secon param is:$1"
}
Param_Test "OK"
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH # 让PATH在bash环境下生效，注意第一行的#!/bin/bash不是注释，表示此shell脚本文件由bash来执行
echo -e "Hello Shell!Starting \a \n"
read -p "Please input your First name:" firstname #打印信息让用户输入firstname
read -p "Please input your Last  name:" lastname #输入lastname
echo "Your Full name is: $firstname $lastname"
Year=$(date +%y) #用date指令来读取年信息
Mont=$(date +%m) #读取月信息
Day=$(date +%d) #读取日信息
filename=$Year"年"$Mont"月"$Day"日"
echo "$filename"
cd /home/ubuntu-mm/UbuntuLearn/Commond/Bash_Shell
Cur_PATH=$(pwd) #pwd指令提取当前的目录，lpwd在SFTP服务中提取本机当前目录，get下载文件，put上传文件
echo "The Current PATH I am in is:$Cur_PATH"
touch $filename".txt"
sudo chmod 777 $($filename".txt")
Calc=$(( 12 % 5 )) #Shell脚本的计算器
echo "The Result Of Equation 12%5 is equal to:$Calc"
F_PATH=/home/ubuntu-mm/UbuntuLearn/Commond/Bash_Shell
test -e "/home/ubuntu-mm/UbuntuLearn/Commond/Bash_Shell" && echo "exist!" || echo "Not exist!" #测试文件名是否存在
test -f $($F_PATH"/txt") && echo "The File Shell_Learn.sh is exist!" || echo "The File Shell_Learn.sh isn't exist!" #测试文件名是否存在且为文件
test -d $F_PATH && echo "The Directory is exist! & It's a Directory!" || echo "The Directory isn't exist!" #测试文件夹是否存在且为目录
test -r $F_PATH && Param="$Param readable" #测试文件的几个权限 rwx
test -w $F_PATH && Param="$Param writable"
test -x $F_PATH && Param="$Param execable"
echo "The Permiissions are:$Param"
Compare="MM1994UESTC"
[ $name -e "MM" ] && echo "Right Name!" || echo "Wrong Name!"
read -p "Are you sure to install the App?[Y/n]" Yn
[ "$Yn" -e "y" -o "$Yn" -e "Y" ] && echo "Nowtime,Starting Install!" || echo "Quit!" #采用[ X == X ]来进行条件判断
file $F_PATH #采用file指令来查看对应 文件参数信息
echo "The Name of the Shell Script is ==> $0" #输出第一个参数，也就是脚本的名称
echo "The Numb of the Script Param is ==> $#" #输出参数的总数量
echo "The whole parameters are ==> $@" #输出所有参数
echo "The First Param is ==> $1" #输出参数1
echo "The Secon Param is ==> $2" #输出参数2
shift #输入变量偏移
echo "The Num of Parameters are ==> $#"
echo "The Whole Parameters are ==> $@"
S=0 #定义整形变量S=0
if [ $S -le 4 ]; then
	let S=S+1 #用let指令让S变量VAR来自加1
	echo "$S" #输出变量S
fi
if [ $S -ge 2 ]; then #多重if判断结构
	echo "Good!"
elif [ $S -le 10 ]; then #elif结构和python相似
	echo "Bad!"
fi
File=$F_PATH"/"$filename".txt"
echo $File
sudo netstat -ntulp | grep "LISTEN" > $File
Param="Shell"
case $Param in #case语句
	"Shell")
	echo "You choice:Shell Script!"
	;;
	"Python")
	echo "You choice:Python Langu!"
	;;
	"Cpp")
	echo "You choice:C plus Langu!"
	;;
	"C")
	echo "You choice:C Langu!"
	;;
	*)
	echo "No Lang you choose!"
	;;
esac
Count=0
while [ $Count -le 5 ] && [ $Count -ne 4 ] #while语句
do
	echo $Count
	let Count=Count+1
done
echo $Count
until [ $Count -ge 10 ] #until语句
do
	echo $Count
	let Count=Count+1
done
for animals in cat dog elephant #类似于Python里面的语法 for i in range(10):...
do
	echo "There are ${animals}s.." #注意能够使用{}来进行变量的区别划分
done
network="192.168.1."
for mask in $(seq 100 110) #学会使用seq命令来完成数字序列的生成
do 
	ping -c 1 -w 1 ${network}${mask} > /dev/null && echo "IP_Address ${network}${mask} is UP!" || echo "IP_Address ${network}${mask} is DOWN!"
done
S=0
for ((i=0;i<=100;i++)) #使用()的形式来完成循环的初始值+步长+终止值
do
	S=$(($S+$i)) #注意加法的方式！
done
echo "1+2+3+...+100=$S"
#exit 0
