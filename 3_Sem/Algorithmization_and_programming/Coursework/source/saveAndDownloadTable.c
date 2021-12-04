
#include "../headers/saveAndDownloadTable.h"

//==============================================================================
//                    ������� ���������� � �������� �������
//==============================================================================

// ��������� ������� � ����
void saveTable(Element *head) {
	system("cls");

	if (head == NULL) {
		printf("\n\n\a C�������� ������! \n\n\n ");
		system("pause");
		return;
	}

	FILE *fdownload;
	int exitFromWhile = 0;
	int lenBuf = 0;

	//���� ���� � ����� ��� ����� ���������
	char buf[255];
	do {
		memset(buf, 0, sizeof(buf));
		system("cls");
		SetBacklightOff;
		gotoxy(0, 0);
		printf("\n ������� ���� � ����� ����������:\n\n");
		printf(" (��������: \"D:\\coursework\\saves\\save1.txt\")\n");
		printf(" (���� ����� �� ������������, �� ����� ������)");
		gotoxy(34, 1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);

		// ��������� ��������� ���� ��� ���, � ���� ��� �� ���� ���� �� }{*#
		lenBuf = strlen(buf);
		if (lenBuf > 4) {
			if ((buf[lenBuf-4] == '.') && (buf[lenBuf-3] == 't') && (buf[lenBuf-2] == 'x') && (buf[lenBuf-1] == 't')) {
				SetBacklightOff;
			}
			else {
				SetBacklightOff;
				printf("\a");
				continue;
			}
		}
		else {
			SetBacklightOff;
			printf("\a");
			continue;
		}

		//���� ���� ��� ���������� ������������ ���?
		if ((fdownload = fopen(buf, "r")) != NULL) {
			const char *overwrite[] = {
				" ��, ����� �����������",
				" ���, �������� ������� �����",
				" � ���� �����, ��������� ��������� �������"
			};
			fclose(fdownload);
			switch(menu(overwrite, 3, " ��������� ���� ��� ����������. ����������� ���?")) {
				case 0: {
					//������� �� ����� 
					fdownload = fopen(buf, "w");
					exitFromWhile = 1;
					break;
				}
				case 1: {
					exitFromWhile = 2;
					break;
				}
				case 2: {
					return;
				}
			}
			if (exitFromWhile == 1) break;
			if (exitFromWhile == 2) continue;
		}

		if ((fdownload = fopen(buf, "w")) != NULL) {
			exitFromWhile = 1;
		}
		else {
			printf("\a");
			const char *error[] = {
				" ��������� ������� �����",
				" �����"
			};
			if (menu(error, 2, " �� ������� �������� ������ � �����!") == 1) {
				return;
			}
		}
	} while (exitFromWhile != 1);

	fseek(fdownload, 0, SEEK_SET);
	while (head != NULL) {
		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_shop, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_section, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.num_receipt);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_name);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_code);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_price, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_quantity, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.day, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.month, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.year, buf, 10);
		fputs(buf, fdownload);
		if (head->next != NULL){
			fputc('\n', fdownload);
		}

		head = head->next;
	}

	fclose(fdownload);

	system("cls");
	printf("\n\n ������� ������� ���������! \n\n\n ");
	system("pause");
	return;
}


// ������� ������� �� �����
void readTable(Element **head) {
	FILE *fread;

	//���� ���� � �����
	char buf[255];
	while(1) {
		memset(buf, 0, sizeof(buf));
		system("cls");
		SetBacklightOff;
		gotoxy(0,0);
		printf("\n ������� ���� � ����� ��������:\n\n");
		printf(" (��������: \"D:\\coursework\\saves\\save1.txt\")");
		gotoxy(32 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		SetBacklightOff;

		//���� ���� �� ��������
		if ((fread = fopen(buf, "r")) == NULL) {
			printf("\a");
			const char *error[] = {
				" ��������� ������� �����",
				" �����"
			};
			if (menu(error, 2, " ���� �� ������!") == 1) {
				break;
			}
		}
		else {
			Info info;

			fseek(fread, 0, SEEK_SET);
			while(!feof(fread)) {
				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.num_shop = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.num_section = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 21, fread); // ������� 20 �������� (\n �� ���������)
				strcpy(info.num_receipt, buf);
				fgets(buf, 21, fread);//������ �������� ����� ������ ������������

				memset(buf, 0, sizeof(buf));
				memset(info.product_name, 0, sizeof(info.product_name));
				fgets(buf, 55, fread);
				strncpy(info.product_name, buf, (strlen(buf)-1));

				memset(buf, 0, sizeof(buf));
				memset(info.product_code, 0, sizeof(info.product_code));
				fgets(buf, 25, fread);
				strncpy(info.product_code, buf, (strlen(buf)-1));

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.product_price = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.product_quantity = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.day = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.month = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.year = atoi(buf);

				addNewElement(head, info);
			}

			fclose(fread);
			system("cls");
			printf("\n\n ���������� ���� ������� ������� �� �����! \n\n ");
			system("pause");
			break;
		}
	}
}


//============================================================================================================================


// ������� ������� �� ��������� �����
void readTableBIN(Element **head) {
	FILE *fread;

	//���� ���� � �����
	char buf[255];
	while(1) {
		memset(buf, 0, sizeof(buf));
		system("cls");
		SetBacklightOff;
		gotoxy(0,0);
		printf("\n ������� ���� � ����� ��������:\n\n");
		printf(" (��������: \"D:\\coursework\\saves\\save1.bin\")");
		gotoxy(32 ,1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);
		SetBacklightOff;

		//���� ���� �� ��������
		if ((fread = fopen(buf, "rb")) == NULL) {
			printf("\a");
			const char *error[] = {
				" ��������� ������� �����",
				" �����"
			};
			if (menu(error, 2, " ���� �� ������!") == 1) {
				break;
			}
		}
		else {
			Info info;

			fseek(fread, 0, SEEK_SET);
			while(!feof(fread)) {
				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.num_shop = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.num_section = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 21, fread); // ������� 20 �������� (\n �� ���������)
				strcpy(info.num_receipt, buf);
				fgets(buf, 21, fread);//������ �������� ����� ������ ������������

				memset(buf, 0, sizeof(buf));
				memset(info.product_name, 0, sizeof(info.product_name));
				fgets(buf, 55, fread);
				strncpy(info.product_name, buf, (strlen(buf)-1));

				memset(buf, 0, sizeof(buf));
				memset(info.product_code, 0, sizeof(info.product_code));
				fgets(buf, 25, fread);
				strncpy(info.product_code, buf, (strlen(buf)-1));

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.product_price = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 15, fread);
				info.product_quantity = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.day = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.month = atoi(buf);

				memset(buf, 0, sizeof(buf));
				fgets(buf, 10, fread);
				info.date.year = atoi(buf);

				addNewElement(head, info);
			}

			fclose(fread);
			system("cls");
			printf("\n\n ���������� ���� ������� ������� �� �����! \n\n ");
			system("pause");
			break;
		}
	}
}


// ��������� ������� � �������� ����
void saveTableBIN(Element *head) {
	system("cls");

	if (head == NULL) {
		printf("\n\n\a C�������� ������! \n\n\n ");
		system("pause");
		return;
	}

	FILE *fdownload;
	int exitFromWhile = 0;
	int lenBuf = 0;

	//���� ���� � ����� ��� ����� ���������
	char buf[255];
	do {
		memset(buf, 0, sizeof(buf));
		system("cls");
		SetBacklightOff;
		gotoxy(0, 0);
		printf("\n ������� ���� � ����� ����������:\n\n");
		printf(" (��������: \"D:\\coursework\\saves\\save1.bin\")\n");
		printf(" (���� ����� �� ������������, �� ����� ������)");
		gotoxy(34, 1);
		SetBacklightYellow;
		fflush(stdin);
		gets(buf);

		// ��������� ��������� ���� ��� ���, � ���� ��� �� ���� ���� �� }{*#
		lenBuf = strlen(buf);
		if (lenBuf > 4) {
			if ((buf[lenBuf-4] == '.') && (buf[lenBuf-3] == 'b') && (buf[lenBuf-2] == 'i') && (buf[lenBuf-1] == 'n')) {
				SetBacklightOff;
			}
			else {
				SetBacklightOff;
				printf("\a");
				continue;
			}
		}
		else {
			SetBacklightOff;
			printf("\a");
			continue;
		}

		//���� ���� ��� ���������� ������������ ���?
		if ((fdownload = fopen(buf, "rb")) != NULL) {
			const char *overwrite[] = {
				" ��, ����� �����������",
				" ���, �������� ������� �����",
				" � ���� �����, ��������� ��������� �������"
			};
			fclose(fdownload);
			switch(menu(overwrite, 3, " ��������� ���� ��� ����������. ����������� ���?")) {
				case 0: {
					//������� �� ����� 
					fdownload = fopen(buf, "wb");
					exitFromWhile = 1;
					break;
				}
				case 1: {
					exitFromWhile = 2;
					break;
				}
				case 2: {
					return;
				}
			}
			if (exitFromWhile == 1) break;
			if (exitFromWhile == 2) continue;
		}

		if ((fdownload = fopen(buf, "wb")) != NULL) {
			exitFromWhile = 1;
		}
		else {
			printf("\a");
			const char *error[] = {
				" ��������� ������� �����",
				" �����"
			};
			if (menu(error, 2, " �� ������� �������� ������ � �����!") == 1) {
				return;
			}
		}
	} while (exitFromWhile != 1);

	fseek(fdownload, 0, SEEK_SET);
	while (head != NULL) {
		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_shop, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_section, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.num_receipt);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_name);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_code);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_price, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_quantity, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.day, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.month, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.year, buf, 10);
		fputs(buf, fdownload);
		if (head->next != NULL){
			fputc('\n', fdownload);
		}

		head = head->next;
	}

	fclose(fdownload);

	system("cls");
	printf("\n\n ������� ������� ���������! \n\n\n ");
	system("pause");
	return;
}


//============================================================================================================================


//�������������� ���������� ������� � ������� .bin (�������������� ����)
void autoSaveTableBin(Element *head) {
	FILE *fdownload;
	int exitFromWhile = 0;
	int lenBuf = 0;

	//���� � ����� � ��� ��������
	char buf[255] = "autoSave.bin";
	if ((fdownload = fopen(buf, "wb")) == NULL) {
		return;
	}
	
	fseek(fdownload, 0, SEEK_SET);
	while (head != NULL) {
		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_shop, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.num_section, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.num_receipt);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_name);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		strcpy(buf, head->data.product_code);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_price, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.product_quantity, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.day, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.month, buf, 10);
		fputs(buf, fdownload);
		fputc('\n', fdownload);

		memset(buf, 0, sizeof(buf));
		itoa(head->data.date.year, buf, 10);
		fputs(buf, fdownload);
		if (head->next != NULL){
			fputc('\n', fdownload);
		}

		head = head->next;
	}

	fclose(fdownload);
	return;
}


// �������������� �������� ���������� ���������� � ������� .bin (�������������� ����)
void autoDownloudTableBin(Element **head) {
	FILE *fread;

	//���� � ����� � ��� ��������
	char buf[255] = "autoSave.bin";
	if ((fread = fopen(buf, "rb")) == NULL) {
		return;
	}

	Info info;

	fseek(fread, 0, SEEK_SET);
	while(!feof(fread)) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, 15, fread);
		info.num_shop = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 15, fread);
		info.num_section = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 21, fread); // ������� 20 �������� (\n �� ���������)
		strcpy(info.num_receipt, buf);
		fgets(buf, 21, fread);//������ �������� ����� ������ ������������

		memset(buf, 0, sizeof(buf));
		memset(info.product_name, 0, sizeof(info.product_name));
		fgets(buf, 55, fread);
		strncpy(info.product_name, buf, (strlen(buf)-1));

		memset(buf, 0, sizeof(buf));
		memset(info.product_code, 0, sizeof(info.product_code));
		fgets(buf, 25, fread);
		strncpy(info.product_code, buf, (strlen(buf)-1));

		memset(buf, 0, sizeof(buf));
		fgets(buf, 15, fread);
		info.product_price = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 15, fread);
		info.product_quantity = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 10, fread);
		info.date.day = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 10, fread);
		info.date.month = atoi(buf);

		memset(buf, 0, sizeof(buf));
		fgets(buf, 10, fread);
		info.date.year = atoi(buf);

		addNewElement(head, info);
	}

	fclose(fread);
	return;
}