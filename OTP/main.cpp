#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>


std::string encryption(std::vector<std::string> plain, std::vector<char> pad)//��ȣȭ
{
	std::string result;
	int x = 0;
	for (int i = 0; i < plain.size(); i++)
	{
		for (int j = 0; j < plain[i].size(); j++)
		{
				std::string temp;
				temp = plain[i][j] ^ pad[x++];
				result += temp;
		}
	}
	return result;
}
std::string decryption(std::string encrypted_, std::vector<char> pad)//��ȣȭ
{
	std::string result;
	int x = 0;
	for (int i = 0; i < encrypted_.size(); i++)
	{
			std::string temp;
			temp = encrypted_[i] ^ pad[x++];
			result += temp;
	}
	
return result;
}
void createOtp(std::vector<std::string> plain, std::string out, std::vector<char>& otp_)//�� ���̸�ŭ pad ����
{
	std::ofstream otp(out);//��ȣ�� ����
	int x = 0;
	for (int i = 0; i < plain.size(); i++)
	{
		for (int j = 0; j < plain[i].size(); j++)
		{
				otp_.push_back((char)rand());
		}
	}
	for (auto it : otp_)
	{
		otp << otp_[it];
	}


}
int main(void)
{
	std::string input_file; //�� txt
	std::string OTP_file; // ������ �е�
	std::string enc_file; //��ȣ�� txt
	std::string dec_file;
	std::vector<std::string> plain_text;//��
	std::vector<char> otp;//otp
	std::string encrypted;//��ȣ��
	std::string decrypted;//��ȣ��
	srand(time(NULL));

	std::cout << "input file name : ";
	std::cin >> input_file;
	std::cout << "encrypted file name : ";
	std::cin >> enc_file;
	std::cout << "decrypted file name : ";
	std::cin >> dec_file;
	OTP_file = "otp.txt";

	std::ifstream read_file(input_file);//��
	std::ofstream enc_file_out(enc_file);//��ȣ�� ����
	std::ofstream dec_file_out(dec_file);//��ȣ�� ����

	if (read_file.is_open())//�� �о����
	{
		while (!read_file.eof())
		{
			std::string s;
			std::getline(read_file, s);
			s += '\n';//���๮�� �߰�
			plain_text.push_back(s);
		}
	}

	createOtp(plain_text, OTP_file, otp);
	encrypted = encryption(plain_text, otp);
	enc_file_out << encrypted;
	decrypted = decryption(encrypted, otp);
	dec_file_out << decrypted;
	
	return 0;
}