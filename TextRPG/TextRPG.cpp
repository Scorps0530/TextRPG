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
	tPlayer = SelectJob(); // 플레이어 직업 선택

	while (true)
	{
		system("cls");

		Render(&tPlayer);

		printf("1.사냥터   2. 능력치 강화   3.종료    : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case FIELD: Field(&tPlayer);  break;
		case UPGRADE: Upgrade(&tPlayer); break;
		case EXIT:
			int nInfo;
			printf("나가게된다면 능력치, 직업 등이 모두 초기화 됩니다.\n그래도 종료하시겠습니까?\n1. YES   2. NO   : ");
			scanf("%d", &nInfo);
			switch (nInfo)
			{
			case YES: printf("종료\n"); system("pause");  break;
			default: printf("종료 해제\n"); main();
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

	printf("직업을 선택해주세요.\n");
	printf("1.전사  2.마법사  3.도적\n");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case WORRIOR:
		strcpy(tInfo.m_strName, "전사");
		tInfo.m_maxHP = 100;
		tInfo.m_curHP = tInfo.m_maxHP;
		tInfo.m_atk = 10;
		break;
	case MAGICIAN:
		strcpy(tInfo.m_strName, "마법사");
		tInfo.m_maxHP = 80;
		tInfo.m_curHP = tInfo.m_maxHP;
		tInfo.m_atk = 12;
		break;
	case THIEF:
		strcpy(tInfo.m_strName, "도적");
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
	printf("직업 : %s\n", pInfo->m_strName);
	printf("체력 : %.1f / %.1f   공격력 : %.1f\n", pInfo->m_curHP, pInfo->m_maxHP, pInfo->m_atk);
	printf("강화 횟수 : %d\n", pInfo->m_upgrade);
	printf("================================\n");
}

void MonsterRender(INFO * pInfo)
{
	printf("================================\n");
	printf("몬스터 이름 : %s\n", pInfo->m_strName);
	printf("체력 : %.1f / %.1f   공격력 : %.1f\n", pInfo->m_curHP, pInfo->m_maxHP, pInfo->m_atk);
	printf("================================\n");
}

void Field(INFO * pInfo)
{
	int nInput = 0;
	INFO tArrMonster[3];

	// 사냥터 루프
	while (true)
	{
		system("cls"); // 클리어 스크린
		Render(pInfo); // 플레이어 정보 출력
		DrawMap();	   // 맵 선택

		scanf("%d", &nInput);

		switch (nInput)
		{
		case MAP1: case MAP2: case MAP3:
			// 몬스터 생성, 전투
			CreateMonster(tArrMonster);
			Fight(pInfo, &tArrMonster[nInput-1], nInput);
			break;
		case PREV: return;
		}
	}
}

void DrawMap()
{
	printf("1. 초보맵\n");
	printf("2. 중수맵\n");
	printf("3. 고수맵\n");
	printf("4. 이전으로\n");
	printf("===============\n");
	printf("맵을 선택하세요. : ");
}

void CreateMonster(INFO * pInfo)
{
	strcpy(pInfo[0].m_strName, "슬라임");
	strcpy(pInfo[1].m_strName, "고블린");
	strcpy(pInfo[2].m_strName, "오우거");

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

		printf("1.공격   2.도망\n");
		printf("메뉴를 선택해주세요 : ");
		scanf("%d", &nInput);

		switch (nInput)
		{
		case ATTACK:
			pPlayer->m_curHP -= pMonster->m_atk;
			pMonster->m_curHP -= pPlayer->m_atk;

			if (pPlayer->m_curHP <= 0)
			{
				printf("플레이어가 죽었습니다.\n");
				system("pause");
				pPlayer->m_curHP = pPlayer->m_maxHP;
				return;
			}
			else if (pMonster->m_curHP <= 0)
			{
				printf("몬스터를 처치했습니다.\n");
				
				switch (field)
				{
				case MAP1: pPlayer->m_upgrade += 1; printf("강화 횟수가 1 증가하였습니다.\n"); break;
				case MAP2: pPlayer->m_upgrade += 2; printf("강화 횟수가 2 증가하였습니다.\n"); break;
				case MAP3: pPlayer->m_upgrade += 3; printf("강화 횟수가 3 증가하였습니다.\n"); break;
				}

				return;
			}
			break;
		case ESCAPE:
			printf("몬스터에게서 도망쳤습니다.\n");
			system("pause");
			return;
		}
	}
}

void Upgrade(INFO* pInfo)
{
	int nInput = 0;

	printf("업그레이드 횟수: %d\n", pInfo->m_upgrade);
	printf("1. 설명 보기   2. 설명 스킵    : ");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case YES: Upgrade_Inform();
	default:
		break;
	}

	nInput = 0;
	printf("업그레이드를 하시겠습니까? 강화 횟수가 1 줄어듭니다.\n");
	printf("1. YES   2. NO    : ");
	scanf("%d", &nInput);

	switch (nInput)
	{
	case YES:
		switch (pInfo->m_upgrade)
		{
		case 0:
			printf("강화 횟수가 0입니다...\n");
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
	printf("\n업그레이드는 한 횟수당 각 능력치가 0.1 증가합니다.\n강화 횟수는 전투로 인하여 얻을 수 있습니다.\n초보용은 1개, 중급용은 2개, 상급용은 3개 얻을 수 있습니다.\n능력치를 무한으로 만들어서 신이 되고 모든 몬스터를 이겨보세요!\n\n");
	return;
}

void Upgrade_Main(INFO * pInfo)
{
	int nInfo = 0;

	system("cls");
	printf("어떤 스탯을 강화하시겠습니까?\n");
	printf("1. 공격력   2. 체력    : ");
	scanf("%d", &nInfo);
	
	switch (nInfo)
	{
	case DAMADGE:
		pInfo->m_atk += 0.1;
		pInfo->m_upgrade -= 1;
		printf("당신의 공격력이 0.1 증가하였습니다.\n");
		printf("남은 강화 횟수는 %d입니다.\n", pInfo->m_upgrade);
		break;
	case HEALTH:
		pInfo->m_maxHP += 0.1;
		pInfo->m_upgrade -= 1;
		printf("당신의 체력이 0.1 증가하였습니다.\n");
		printf("남은 강화 횟수는 %d입니다.\n", pInfo->m_upgrade);
		break;
	default:
		printf("올바른 답을 적으시오.\n");
		break;
	}
	return;
}
