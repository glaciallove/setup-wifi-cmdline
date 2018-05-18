#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char** argv){
	FILE *fp;
	char a[]="country=US\nctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\t\nupdate_config=1\n\nnetwork={\n\tssid=\"";
	char b[]="\"\n\tscan_ssid=1\n\tpsk=\"";
	char c[]="\"\n\tkey_mgmt=WPA-PSK\n}\n";
	char name[]="your-wifi-name";
	char password[]="password";
	fp=fopen("/etc/wpa_supplicant/wpa_supplicant.conf","wb+");
	if(argc==4){						//network name with a space e.g. a hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(" ",1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[3],strlen(argv[3]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else if(argc==3){					//network name e.g. a_hostel
		fwrite(a,sizeof a-1,1,fp);
		fwrite(argv[1],strlen(argv[1]),1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(argv[2],strlen(argv[2]),1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else if(argc==1){      				//network name & password to be set at line 10 &11
		fwrite(a,sizeof a-1,1,fp);
		fwrite(name,sizeof name-1,1,fp);
		fwrite(b,sizeof b-1,1,fp);
		fwrite(password,sizeof password-1,1,fp);
		fwrite(c,sizeof c-1,1,fp);
	}else{
		printf("input error\n");
		exit(1);
	}
	fclose(fp);
	system("sudo systemctl restart dhcpcd");
	return 0;
}
