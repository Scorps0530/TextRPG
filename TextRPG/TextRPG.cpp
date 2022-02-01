#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "const.h"

#pragma warning(disable : 4996)

typedef struct _tagInfo
{
	char m_strName[32];
	float m_curHP;
	float m_maxHP;
	float m_atk;
	int m_upgrade;
}INFO;

void Logo();
INFO SelectJob();
void Render(INFO* pInfo);
void MonsterRender(INFO* pInfo);
void Field(INFO* pInfo);
void DrawMap();
void CreateMonster(INFO* pInfo);
void Fight(INFO* pPlayer, INFO* pMonster, int Field);
void Upgrade(INFO* pInfo);
void Upgrade_Inform();
void Upgrade_Main(INFO* pInfo);

int main()
{
	system("mode con:cols=230 lines=80");

	int nInput = 0;
	INFO tPlayer;

	Logo();
	tPlayer = SelectJob(); // �÷��̾� ���� ����

	while (true)
	{
		system("cls");

		Render(&tPlayer);

		printf("1.�����   2. �ɷ�ġ ��ȭ   3.����    : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case FIELD: Field(&tPlayer);  break;
		case UPGRADE: Upgrade(&tPlayer); break;
		case EXIT:
			int nInfo;
			printf("�����Եȴٸ� �ɷ�ġ, ���� ���� ��� �ʱ�ȭ �˴ϴ�.\n�׷��� �����Ͻðڽ��ϱ�?\n1. YES   2. NO   : ");
			scanf("%d", &nInfo);
			switch (nInfo)
			{
			case YES: printf("����\n"); system("pause");  break;
			default: printf("���� ����\n"); main();
			}
			break;
		}
	}
	
	return 0;
}

void Logo()
{
 printf("      UMGKE0E0ZZZ0E0ZZZZZKZZZ0ZKZZEKE0EKE0ZKE0E0EZZ0E0E0EKE0Z0EKE0ZKE0E0EZE0Z0E0EZEKZ0E0EZOM   \n");    
 printf("      2BZE0E0E0EKEKEKE0E0E0E0Z0Z0E0EKE0E0Z0EKE0Z0E0E0EKE0E0E0ZZE0EKE0EZEZEKE0EZZ0Z0E0EKZKEDB   \n");    
 printf("      UMGZZ0Z0ZZE0Z0EKEKE0Z0E0E0EKE0E0E0ZKE0E0EKEKE0E0EKEKZ0E0E0ZKE0E0E0EKZ0E0ZKZ0E0E0E0E0OM   \n");    
 printf("      3BZZ0E0Z0EKZ0EKE0EKEKZ0ZZZKEKZ0EZE0ZKE0EZZ0Z0E0E0E0Z0E0E0EZZKZZZ0ZKZ0E0E0EKEKZKE0EKEDB   \n");    
 printf("      UMDKZKE0E0Z0E0E0ZKE0E0EKZ0E0EKE0EKZKE0E0ZZE0E0Z0EKE0E0ZZEZEKZ0EKE0E0ZKEKEZEKE0EZZ0EZOM   \n");    
 printf("      2BEEKEKEKE0Z0EKE0ZKE0ZKE0E0E0ZZEKEKE0E0Z0EEEZGZEZEZE0E0ZKE0ZKEKE0Z0EKZZZKE0ZZE0E0EZEGB   \n");    
 printf("      FMG0E0E0E0Z0Z0EKE0EKZ0E0E0EKEZE0EKE0EZDEORMBBMBMMOOEDZE0Z0E0EKE0E0Z0E0EZEKE0Z0EKEKEKOB   \n");    
 printf("      2BZZKEKZ0E0E0EZE0EZEZE0EKEZE0Z0Z0ZZGDMMBBBODXXXGOBBBMOEEKE0E0Z0E0E0E0ZZZKZ0EKZ0E0E0EDB   \n");    
 printf("      FMDKEKZKZZZKZKE0E0Z0EZE0E0Z0EKE0EGOMBRU:          .rDMBOWZG0EKZ0EKE0Z0EKEKZZE0EKZKE0OB   \n");    
 printf("      2BEZ0ZKE0E0Z0Z0E0EKEKEKEKEZZ0Z0GGBMK.                 xBMOEEZEZZKEKZKEZZKZKE0EZE0ZZEDB   \n");    
 printf("      UMD0E0ZZE0EKEKEKE0EKZ0E0ZKE0EZDOBD.                     FMMEG0Z0E0Z0Z0EZZ0Z0Z0E0EKE0OM   \n");    
 printf("      1BEEKZ0Z0EKZ0EZE0E0E0ZKZ0EZZZGRB7                        ,MRDD0GZE0E0E0E0E0E0E0ZZEKEDB   \n");    
 printf("      UMD0Z0EKEKEZE0Z0E0Z0E0E0EKEKGRB:                          iWZEWZG0EKEKZ0E0E0E0E0EKE0OM   \n");    
 printf("      2BEEZEZZ0Z0EKE0Z0Z0EKE0EZEKEDB;         iUKOOOWOE1:       :O3SPWEG0EKZ0Z0ZKEKE0E0E0EDB   \n");    
 printf("      UMGKE0ZZEKE0Z0EZEKE0EKZ0E0EEB1        JOREPHHSSHEWBK.     KKS21UKEDZGKEZZ0EKEKE0ZZZZWM   \n");    
 printf("      1BZE0E0EKZ0EKZ0ZKEZEZZKEKEZMM       .ROPFF2U311FUSSOOL,.:ZGSUSU11SXGGD0EKEKE0Z0EKE0ZDB   \n");    
 printf("      UMD0ZKE0E0EKEZZKEZEZE0E0Z0DML      .MKS213U213F1U1SFXWRRR0HFSUSUSUFUKEDZE0EKE0Z0ZKZZWM   \n");    
 printf("      1BZE0E0EZE0Z0E0E0EKE0ZZEZGOB       EGS2131312U2S2F1F1SSSSHUSUSFHSSFSUSXEEDKZ0EZZKEKGGB   \n");    
 printf("      UMG0E0EZZ0E0E0E0EKEKEZEZEZBD      ;RH213U312S1U1SUF2SUFFSUSUSSHSSSSSSSSSKZGZEZEKEKZZWM   \n");    
 printf("      1BZEKE0E0ZKEZZ0E0E0E0Z0EKDMJ      FWU13U311S1F1UUU2SUSUSFSUSSSSSFSSHSHSSUHPGZG0E0ZZGDB   \n");    
 printf("      1MG0EZZZE0EKZKEKZ0EZZ0E0EEBr      DHF3U212F1U2S1U2SFSFSUSFSFHFHSSSSSHSXSXSSS0ZGZE0Z0WM   \n");    
 printf("      3BEEKE0EKE0EKZZZKEKZ0E0E0DB;      DP1U311S1FUF1F2UUSUSUSUSFSFSFSSHSXSHSHSXSXUHXEZGZEGB   \n");    
 printf("      FMG0Z0E0E0Z0E0EZZ0ZKE0E0ZEBi      WXU312FUS1F1S1SUSFSUSUSFSFSSSSHSHSHSXHPSXSXSXH0ZGZOM   \n");    
 printf("      1BZZ0E0E0E0EKZ0ZKE0EZZ0E0DML      PZ112FUS2S1F2SFSFSUSUSSSFSSHSHSHSXSPSXSXSHHKXPHPPEWB   \n");    
 printf("      1BG0EKZZE0E0ZZE0EZZZZ0Z0ZEBS      LOF1S1U2S1U1FUS1SUSUSFHFHSSSSSHSHSXHXSHSHHPXPHPHPPGM   \n");    
 printf("      1BZE0E0Z0Z0Z0EKE0EKZKE0E0GRB       MHS1U1FUF1SUSUSUSFSFXSHFSSXSHSXSXHPSPHXSKXPHKPKXK0B   \n");    
 printf("      UME0Z0E0E0EKZZE0Z0Z0EZZZEKWM:      7BHS1FUF1SFSUSFSUSHDDDHHSHSHSXSHSPHXSXSPXPHPH0XKXGM   \n");    
 printf("      2BZE0Z0E0EKE0EKZKEKEZEKEKEZBZ       2BPHUF1FFSUSUSSHGB0SKRDKSHSHSXHXSXHXHKXPHKHKPKXKZB   \n");    
 printf("      UME0EKEZZZEKE0E0EKEZZ0Z0ZZEDB,       7BRZSSSSUHSXHOMW.    0WPSXSHSPSPSXSKXPHPH0PKPKPEM   \n");    
 printf("      1BEE0EKEKEKEKZ0E0ZKEKEZZ0ZZGMB         3OMRRDOWRMBK;       RKXSXSXHXSXSKXPHPX0PKXKHKEB   \n");    
 printf("      UMDKZ0E0E0E0EZEKE0ZKZKZ0EKZZWMO          ,rJUFUsi          KGSXHXSXHXSPXPXKHKPKPKXKKWM   \n");    
 printf("      1BEE0Z0EKE0EZEKEZE0E0EKE0E0E0WMR                          .MXXHXHXSXSKPKXPHKP0XKP0KEGB   \n");    
 printf("      1MDZE0E0Z0E0Z0EZE0Z0EKE0E0E0EZDMB:                       .RGPHHSXSHSPXKHPXKPKXKPKPZKWM   \n");    
 printf("      1BZEKZ0E0EKEZZ0Z0Z0EZE0Z0EZZKZZGRBG:                   .2BDKXXSHHPSKXKXKX0XKXKXKPZPZGB   \n");    
 printf("      UME0EZEKEKZKEKZZE0EKE0EKZ0ZZE0E0DDBMM7.              ;KBMKPHXSXHHSKXKHPH0PKXKPKPZKZKDM   \n");    
 printf("      2BEZKZKZ0ZKEKE0EKZZE0EKE0EKEKZKZ0EZOMBMRS3L7i;;rcuSOMBO0HXSXHHHXSPPPXKH0X0PKPKPZPZPZEB   \n");    
 printf("      UMEKE0ZKZZE0Z0E0Z0E0Z0E0ZKE0E0EKZKEZDGORMOOWMMMRMRREZHPSXSXSHSPSPPPXPXKXKP0PKPZPZPZKWM   \n");    
 printf("      1BZEKE0ZKZKEKEKEKE0EKEZE0EZZ0ZKZZZKZ0EZEEOZXUSSHSPSHSHSHSPSXSXHPXKXPHKPKPKX0PZPZKZPZWB   \n");    
 printf("      UBDKE0ZZEKEKZ0EKE0E0Z0EKE0EZE0E0E0EKZKEKEZGEESF1HSHSHSHHXSXHPSPPKHPHKX0X0X0XZPZPZPZZOM   \n");    
 printf("      1BZZ0E0E0E0EKZ0E0E0Z0E0EZE0EKZKE0E0ZZE0Z0EKEGDKHFSSXSSSXSXSPSPXPHKHKXKP0PKXZPZP0PZ0EDB   \n");    
 printf("      UMDKE0E0ZZGZDEGZGZG0G0EZDZGZG0GZDEEZEZDZE0E0EZWGZSSSSSPHPHXSXPKPKXKPZXKP0KEKEKEK0ZZ0WM   \n");    
 printf("      2BEZ0E0ZZDMBMBROMBMBRDGMMBMREGEBMBMWDBMBMOZGGMRDGRMESP0R0ODKK0OO0RGOOE0DRDZRMBMWZEKEDB   \n");    
 printf("      UMD0ZZEZDRx::;OB1rirWMBE: ;WBOB1:.LRMcr;cRRDBJKBRGLMMRW7RJ2MWM2uMvRSJBRX7RBZ:.i0RZEZOM   \n");    
 printf("      2BZZKZZEDB  i  B  ;. B3  ;  FB: :r HR .;  MBK  BMH .MB  M  HMU .M Wi iML B3 .c :MDKEDB   \n");    
 printf("      UBGKEKE0OM 7BB S iBO G :BMB. M OBvcRB DM7 BB ; :B0  ,.  B.  7  :B Mr  7P M ;BLvJMGEZOM   \n");    
 printf("      2BZE0ZKEWB    .B    rB ;MBM. R BRr ,M    GM: 3, RR O  R M.:s u:,M Ri B   B 7M7  ROKGDB   \n");    
 printf("      1MG0ZKE0WM .BDBM ;B: R3 .i  FM  7x :M RM  S ..,  H RBMR B  MRM  M W: MM  Mv :3  BDE0OB   \n");    
 printf("      3BZE0EKEEMvXMRWR7PMBiSM0: :GMMBs..LBOrOBOr2cMBMBrD7ORMD7RuuBRBuJOiOSvMMErRMH:.;ORGKGWB   \n");    
 printf("      UMG0E0Z0EZMOG0GGMRDDBOORBMBRDEOMBMBWOMOERMMMODWOBOBGGZOMORMZGEMRORWOR0GOMDWMBMBOGZE0OB   \n");    
 printf("      2BZZ0EZE0E0EKE0E0EZGZEZDEDZEZE0GEDEGZEZE0EEG0EZG0EZE0E0EZG0G0G0EZD0ZKZKZZG0GEDEE0Z0EDB   \n");    
 printf("      UMG0E0E0EKZ0E0E0E0EKZZE0EKEZEZEZEZE0EKZ0E0Z0E0EKE0Z0ZZE0Z0E0E0E0EZE0EPZKE0Z0Z0EZEZZKOM   \n");    
 printf("      1BEZ0Z0EZE0E0E0EKEKEZE0Z0E0Z0E0E0ZZEKZ0E0ZKE0Z0E0Z0Z0E0EZEKE0E0EZEZE0G0E0ZKEKEZZ0EKZWB   \n");    
 printf("      1MG0EKE0EKE0EKEKZ0EKEKZKE0E0Z0EKE0E0E0E0E0EKZKZ0Z0EKEKZ0E0EKZZE0ZKE0E0Z0EKZZE0EKEKE0WM   \n");    
 printf("      1BZEZEZEKZZEKZ0E0E0ZKEZEZZZZKEZE0Z0E0EKZKEZZ0E0EKEKZ0E0EKZKEKEZZKE0E0ZZEZZZE0EKEKE0ZGB   \n");    
 printf("      1MGKEKZ0EKEZE0Z0ZZZKEKE0ZKZ0EKEKZKEKZ0EZE0ZKZ0E0E0EKE0Z0EKEKEKE0E0E0EZEKE0EZEZZ0Z0E0WB   \n");    
 printf("      3BZE0Z0E0ZKEKE0E0Z0EZZKEZE0EKE0ZZEKEKEZEKEZZ0Z0ZZEKEKZKE0EKE0E0EZEKEZE0EZEKEKEKE0EKZDB   \n");    
 printf("      SMGZE0EZEZG0E0EZGZG0E0GZE0E0EZE0EZE0EZGZE0E0E0GZEZG0E0G0E0G0G0E0EZE0EZEZE0E0EZG0E0E0OM.  \n");    
 printf("      0BRRORRRRRRRORORORRRORORORORRRORORORORRRRRRRORRRORORORORRRRRRRORRRRRORRRRRORORRRORORMB.  \n");    
 printf("      :MBMBMBMBMBMBMBMBBBMBMBBBBBMBMBMBMBMBBBMBBBMBBBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBMBK   \n");
 printf("                                           press to start                                      \n");
  system("pause");
  system("cls");
}																																	   

INFO SelectJob()
{
	int nInput = 0;
	INFO tInfo = { "", };

	printf("������ �������ּ���.\n");
	printf("1.����  2.������  3.����\n");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case WORRIOR:
		strcpy(tInfo.m_strName, "����");
		tInfo.m_maxHP = 100;
		tInfo.m_curHP = tInfo.m_maxHP;
		tInfo.m_atk = 10;
		break;
	case MAGICIAN:
		strcpy(tInfo.m_strName, "������");
		tInfo.m_maxHP = 80;
		tInfo.m_curHP = tInfo.m_maxHP;
		tInfo.m_atk = 12;
		break;
	case THIEF:
		strcpy(tInfo.m_strName, "����");
		tInfo.m_maxHP = 70;
		tInfo.m_curHP = tInfo.m_maxHP;
		tInfo.m_atk = 14;
		break;
	}

	return tInfo;
}

void Render(INFO * pInfo)
{
	printf("================================\n");
	printf("���� : %s\n", pInfo->m_strName);
	printf("ü�� : %.1f / %.1f   ���ݷ� : %.1f\n", pInfo->m_curHP, pInfo->m_maxHP, pInfo->m_atk);
	printf("��ȭ Ƚ�� : %d\n", pInfo->m_upgrade);
	printf("================================\n");
}

void MonsterRender(INFO * pInfo)
{
	printf("================================\n");
	printf("���� �̸� : %s\n", pInfo->m_strName);
	printf("ü�� : %.1f / %.1f   ���ݷ� : %.1f\n", pInfo->m_curHP, pInfo->m_maxHP, pInfo->m_atk);
	printf("================================\n");
}

void Field(INFO * pInfo)
{
	int nInput = 0;
	INFO tArrMonster[3];

	// ����� ����
	while (true)
	{
		system("cls"); // Ŭ���� ��ũ��
		Render(pInfo); // �÷��̾� ���� ���
		DrawMap();	   // �� ����

		scanf("%d", &nInput);

		switch (nInput)
		{
		case MAP1: case MAP2: case MAP3:
			// ���� ����, ����
			CreateMonster(tArrMonster);
			Fight(pInfo, &tArrMonster[nInput-1], nInput);
			break;
		case PREV: return;
		}
	}
}

void DrawMap()
{
	printf("1. �ʺ���\n");
	printf("2. �߼���\n");
	printf("3. �����\n");
	printf("4. ��������\n");
	printf("===============\n");
	printf("���� �����ϼ���. : ");
}

void CreateMonster(INFO * pInfo)
{
	strcpy(pInfo[0].m_strName, "������");
	strcpy(pInfo[1].m_strName, "���");
	strcpy(pInfo[2].m_strName, "�����");

	for (int i = 0; i < 3; ++i)
	{
		pInfo[i].m_atk = (i + 1) * 3;
		pInfo[i].m_maxHP = (i + 1) * 30;
		pInfo[i].m_curHP = pInfo[i].m_maxHP;
	}
}

void Fight(INFO * pPlayer, INFO * pMonster, int field)
{
	int nInput = 0;

	while (true)
	{
		system("cls");
		Render(pPlayer);
		Render(pMonster);

		printf("1.����   2.����\n");
		printf("�޴��� �������ּ��� : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case ATTACK:
			pPlayer->m_curHP -= pMonster->m_atk;
			pMonster->m_curHP -= pPlayer->m_atk;

			if (pPlayer->m_curHP <= 0)
			{
				printf("�÷��̾ �׾����ϴ�.\n");
				system("pause");
				pPlayer->m_curHP = pPlayer->m_maxHP;
				return;
			}
			else if (pMonster->m_curHP <= 0)
			{
				printf("���͸� óġ�߽��ϴ�.\n");
				
				switch (field)
				{
				case MAP1: pPlayer->m_upgrade += 1; printf("��ȭ Ƚ���� 1 �����Ͽ����ϴ�.\n"); break;
				case MAP2: pPlayer->m_upgrade += 2; printf("��ȭ Ƚ���� 2 �����Ͽ����ϴ�.\n"); break;
				case MAP3: pPlayer->m_upgrade += 3; printf("��ȭ Ƚ���� 3 �����Ͽ����ϴ�.\n"); break;
				}

				return;
			}
			break;
		case ESCAPE:
			printf("���Ϳ��Լ� �����ƽ��ϴ�.\n");
			system("pause");
			return;
		}
	}
}

void Upgrade(INFO* pInfo)
{
	int nInput = 0;

	printf("���׷��̵� Ƚ��: %d\n", pInfo->m_upgrade);
	printf("1. ���� ����   2. ���� ��ŵ    : ");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case YES: Upgrade_Inform();
	default:
		break;
	}

	nInput = 0;
	printf("���׷��̵带 �Ͻðڽ��ϱ�? ��ȭ Ƚ���� 1 �پ��ϴ�.\n");
	printf("1. YES   2. NO    : ");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case YES:
		switch (pInfo->m_upgrade)
		{
		case 0:
			printf("��ȭ Ƚ���� 0�Դϴ�...\n");
			system("pause");
			break;
		default: Upgrade_Main(pInfo);
			break;
		}
	default:
		break;
	}
	return;
}

void Upgrade_Inform()
{
	printf("\n���׷��̵�� �� Ƚ���� �� �ɷ�ġ�� 0.1 �����մϴ�.\n��ȭ Ƚ���� ������ ���Ͽ� ���� �� �ֽ��ϴ�.\n�ʺ����� 1��, �߱޿��� 2��, ��޿��� 3�� ���� �� �ֽ��ϴ�.\n�ɷ�ġ�� �������� ���� ���� �ǰ� ��� ���͸� �̰ܺ�����!\n\n");
	return;
}

void Upgrade_Main(INFO * pInfo)
{
	int nInfo = 0;

	system("cls");
	printf("� ������ ��ȭ�Ͻðڽ��ϱ�?\n");
	printf("1. ���ݷ�   2. ü��    : ");
	scanf("%d", &nInfo);
	
	switch (nInfo)
	{
	case DAMADGE:
		pInfo->m_atk += 0.1;
		pInfo->m_upgrade -= 1;
		printf("����� ���ݷ��� 0.1 �����Ͽ����ϴ�.\n");
		printf("���� ��ȭ Ƚ���� %d�Դϴ�.\n", pInfo->m_upgrade);
		break;
	case HEALTH:
		pInfo->m_maxHP += 0.1;
		pInfo->m_upgrade -= 1;
		printf("����� ü���� 0.1 �����Ͽ����ϴ�.\n");
		printf("���� ��ȭ Ƚ���� %d�Դϴ�.\n", pInfo->m_upgrade);
		break;
	default:
		printf("�ùٸ� ���� �����ÿ�.\n");
		break;
	}
	return;
}
