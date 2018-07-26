#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv){
	FILE *fp;
	char a[]="network={\n\tssid=\"";
	char b[]="\"\n\tpsk=\"";
	char c[]="\"\n}\n";
	fp=fopen("/etc/wpa_supplicant/wpa_supplicant.conf","a+");
	fseek(fp,0,SEEK_END);
	if(argc==6){						//network name with a space e.g. A a a hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[3],strlen(argv[3]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[4],strlen(argv[4]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[5],strlen(argv[5]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else if(argc==5){					//network name with a space e.g. A a hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[3],strlen(argv[3]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[4],strlen(argv[4]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else if(argc==4){					//network name e.g. A_hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[3],strlen(argv[3]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else if(argc==3){					//network name e.g. A_hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else{
		printf("input error\n");
		exit(1);
	}
	system("sudo systemctl restart dhcpcd");
	fclose(fp);;
	return 0;
}
