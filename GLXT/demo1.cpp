#include<iostream>
using namespace std;

#define MAX 1000



	//封装函数显示该界面
	//在main函数中调用封装好的函数

//菜单功能
void showMain() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出界面" << endl;
}

//添加联系人
//1、设计一个联系人的结构体
//2、设计通讯录结构体
//3、main函数中创建通讯录
//封装添加联系人函数
//测试添加联系人功能


//设计联系人结构体
struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//手机号码
	string m_Addr;//家庭住址
};

//设计通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中人员个数

};

//添加联系人
void addPerson(Addressbooks *abs) {
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size== MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体的联系人

		//姓名
		string name;
		cout<<"请输入姓名" << endl;
		cin >> name;
		//放到通讯录里面
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别（1表示男，2表示女）" << endl;
		

		while (true)
		{
			cin >> sex;
			//如果输入1和2则可退出循环
			//如果输入有误，则重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请输入正确的值" << endl;
			}
		}
		
		

		//年龄
		int age;
		cout << "请输入年龄" << endl;
		

		while (true)
		{
			cin >> age;

			if (age > 1 && age < 100)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "请输入正确的年龄" << endl;
			}
		}	

		//电话号码
		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;


		//住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;

		//添加成功
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

//显示联系人功能
//思路：判断如果当前通讯录没有联系人，就提示记录为空，人数大于0，显示通讯录中的信息

//显示所有人信息的方法
void showPerson(Addressbooks* abs) {
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size==0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_Name <<" ";
			cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << " ";
			cout << "年龄: " << abs->personArray[i].m_Age << " ";
			cout << "电话: " << abs->personArray[i].m_Phone << " ";
			cout << "住址: " << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}


//删除联系人
//1、检测联系人是否存在
//2、封装删除联系人的函数
//3、测试删除联系人的功能

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1				
//参数1：通讯录 参数2：对比的姓名
int isExist(Addressbooks * abs,string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i;//返回这个人在数组中的下标
		}
	}
	return -1;//如果遍历结束都么有找到
}//删除指定的联系人
void deletePerson(Addressbooks *abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;

	cin >> name;
	int result = isExist(abs,name);//result == -1:未查到；result==i：查到数组下标为i的人
	if (result != -1)
	{
		for (int i = result; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录的人数
		cout << "删除成功" << endl;

	}
	else
	{
		cout << "查无此人，无法删除" << endl;
	}

	system("pause");
	system("cls");
}


//查找联系人
void findPerson(Addressbooks *abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;//创建变量接受用户
	cin >> name;

	//判断指定的联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1)//存在
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << " ";
		cout << "性别：" << abs->personArray[ret].m_Sex << " ";
		cout << "年龄：" << abs->personArray[ret].m_Age << " ";
		cout << "电话：" << abs->personArray[ret].m_Phone << " ";
		cout << "住址：" << abs->personArray[ret].m_Addr<< " "<<endl;
	}
	else//不存在
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//修改指定联系人信息
void modifyPerson(Addressbooks * abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		cout << "请输入联系人的姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入联系人的性别" << endl;
		cout << "男性--1" << endl;
		cout << "女性--2" << endl;
		int sex;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请输入正确的性别" << endl;
			}
		}
		
		//年龄
		cout << "请输入联系人的年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入联系人的电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << "请输入联系人的住址" << endl;
		string adress;
		cin >> adress;
		abs->personArray[ret].m_Addr = adress;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
//实现思路：将通讯录记录记录的联系人为0
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


//退出系统

int main() {

	//在main函数中创建真实的通讯录
	Addressbooks abs;
	//初始化通讯录中当前的人员个数
	abs.m_Size = 0;


	int select = 0;//创建用户选择输入的变量

	string name;

	while (true)
	{
		showMain();
		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
		{
			/*cout << "请输入要删除联系人的姓名" << endl;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
			system("pause");
			system("cls");*/
		}
			deletePerson(&abs);
			
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用通讯录" << endl;
			system("pause");
			return 0;
			break;
		}
	}


	
	
	
}