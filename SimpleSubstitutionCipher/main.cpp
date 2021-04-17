#include <iostream>
#include <string>

class Caeser//���� ��ȣ
{
public:
	void encrypt(int key)//��ȣȭ
	{
		key = key % 26;//26 �̻��� ���ڸ� �Է� ���� ��� ���
		for (int i = 0; i < plain_text.length(); i++)//�Է¹��� �� ���̸�ŭ
		{
			if (plain_text[i] == ' ')//������ �״�� ��ȣ���� �Է�
			{
				encrypt_str += plain_text[i];
			}
			else
			{
				if((int)plain_text[i]+key >122)
					encrypt_str += (char)((int)plain_text[i] + key-26);//z�� 122�� �Ѿ ��� -26�� �Ͽ� ������ ������.
				else
					encrypt_str += (char)((int)plain_text[i] + key);//ascii code�̿�. int�� ����� ����ȯ �� ���ڸ� ���ؼ� ���� ��ȣȭ �� char�� �ٽ� ����ȯ
			}			
		}
	}
	void decrypt(int key)//��ȣȭ
	{
		key = key % 26;
		for (int i = 0; i < encrypt_str.length(); i++)
		{
			if (plain_text[i] == ' ')//�����Ͻ� �״�� �Է�
			{
				decrypt_str += encrypt_str[i];
			}
			else
			{
				if ((int)encrypt_str[i] - key < 97)
					decrypt_str += (char)((int)plain_text[i] - key + 26);//a�� 97���� ���� ��� +26�� �Ͽ� z�� �Ѿ�� �Ѵ�.
				else
					decrypt_str += (char)((int)plain_text[i] -key);//ascii code�̿�. int�� ����� ����ȯ �� ���ڸ� ���ؼ� ���� ��ȣȭ �� char�� �ٽ� ����ȯ
			}
		}
	}
	void getPlainText(std::string input_string)//���� �Է¹޴´�.
	{
		plain_text = input_string;
	}
	std::string plain_text;//�Է¹��� ��
	std::string encrypt_str;//��ȣ��
	std::string decrypt_str;//��ȣ��
};

class SimpleSubstitution//���� ġȯ ��ȣ
{
public:
	void encrypt()//��ȣȭ
	{
		for (int i = 0; i < plain_text.length(); i++)
		{
			if (plain_text[i] == ' ')//������ ��� �ٷ� ���ڿ��� �߰�
			{
				encrypt_str += plain_text[i];
			}
			else
			{
				for (int j = 0; j < 27; j++)//�� ���̺�� ���Ͽ� ��ġ �� �� �ش� index�� ������ ��ȣ ���̺� ���ڸ� ���ڿ��� �Է�
				{
					if (plain_text[i] == plain_table[j])
						encrypt_str += encrypt_table[j];
				}
			}
		}
	}
	void decrypt()//��ȣȭ
	{
		for (int i = 0; i < encrypt_str.length(); i++)
		{
			if (encrypt_str[i] == ' ')
			{
				decrypt_str += encrypt_str[i];
			}
			else
			{
				for (int j = 0; j < 27; j++)//��ȣ ���̺�� ���Ͽ� ��ġ �� �� �ش� index�� ������ ��ȣ ���̺� ���ڸ� ���ڿ��� �Է�
				{
					if (encrypt_str[i] == encrypt_table[j])
						decrypt_str += plain_table[j];
				}
			}
		}
	}
	void getPlainText(std::string input_string)
	{
		plain_text = input_string;
	}
	std::string plain_text;//��
	std::string encrypt_str;//��ȣ��
	std::string decrypt_str;//��ȣ��
private:
	char plain_table[27] = "abcdefghijklmnopqrstuvwxyz"; // �� ���̺�
	char encrypt_table[27] = "WYHFXUMTJVSGENBRDZLQAPCOKI";// ��ȣ ���̺�
};

int main()
{
	int cmd;
	std::string input;
	int key;
	Caeser a;
	SimpleSubstitution b;
	while (1)
	{	
		std::cout << "1. caeser encryption\n";
		std::cout << "2. caeser decryption\n";
		std::cout << "3. simple substitution cipher encryption\n";
		std::cout << "4. simple substitution cipher decryption\n";
		std::cout << "5. exit\n";
		std::cout << "Select menu : ";
		std::cin >> cmd;
		std::cin.ignore();
		switch (cmd)
		{
		case 1:
			std::cout << "Enter text to encrypt : ";
			std::getline(std::cin, input);
			std::cout << "enter key : ";
			std::cin >> key;
			a.getPlainText(input);
			a.encrypt(key);
			std::cout << "Text encrypted : " << a.encrypt_str << "\n";
			break;
		case 2:
			std::cout << "Enter text to decrypt : ";
			std::getline(std::cin, input);
			std::cout << "enter key : ";
			std::cin >> key;
			a.getPlainText(input);
			a.decrypt(key);
			std::cout << "Text decrypted : " << a.decrypt_str << "\n";
			break;
		case 3:
			std::cout << "Enter text to encrypt : ";
			std::getline(std::cin, input);
			b.getPlainText(input);
			b.encrypt();
			std::cout << "Text encrypted : " << b.encrypt_str << "\n";
			break;
		case 4:
			std::cout << "Enter text to decrypt : ";
			std::getline(std::cin, input);
			b.getPlainText(input);
			b.decrypt();
			std::cout << "Text decrypted : " << b.decrypt_str << "\n";
			break;
		case 5:
			std::cout << "exit program\n";
			exit(0);
			break;
		}
		std::cout << "-------------------------------------\n";
	}
}