#include <stdio.h>

int convert(FILE* fp_in, FILE* fp_out, int search[], int size, int replace[]);

int main(int argc, char* argv[]) {
	int pattern[] = {0x3D, 0x0A, 0x0A, 0x0A, 0x00, 0x0F, 0x84, 0xEB, 0xFE, 0xFF, 0xFF, 0x3D};
	int crus_pattern_w1[] = {0x28, 0x21, 0xE8, 0x81, 0xFD};
	int crus_pattern_w2[] = {0xFF, 0xFF, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3D};
	int crus_pattern_w3[] = {0x00, 0x0F, 0x94, 0xC2, 0x81, 0xFD};
	int crus_pattern_z[] = {0xC7, 0x44, 0x89, 0xF0, 0x25, 0xFF, 0xFF, 0xFF, 0x00, 0x3D};
	int replace_ip[4];
	int counter = 0;
	//remove old files
	remove("output/GatewayServer");
	remove("output/HTTPAServer");
	remove("output/LoginServer");
	remove("output/MissionServer");
	remove("output/TicketServer");
	remove("output/WorldServer");
	remove("output/WorldServer_1");
	remove("output/WorldServer_2");
	remove("output/WorldServer101");
	remove("output/WorldServer102");
	remove("output/ZoneServer");
	remove("output/ZoneServer101");
	remove("output/ZoneServer102");
	//interface
	printf("Enter new ip:\n");
	scanf("%d.%d.%d.%d", &replace_ip[0], &replace_ip[1], &replace_ip[2], &replace_ip[3]);
	printf("\nUsing %x %x %x\n", replace_ip[0], replace_ip[1], replace_ip[2]);
	//GatewayServer
	FILE* fp_gs_in = fopen("input/GatewayServer", "rb");
	if(fp_gs_in != NULL) {
		FILE* fp_gs_out = fopen("output/GatewayServer", "ab");
		printf("Found %d occurrences in GatewayServer.\n", convert(fp_gs_in, fp_gs_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_gs_out);
	}
	fclose(fp_gs_in);
	//HTTPAServer
	FILE* fp_hs_in = fopen("input/HTTPAServer", "rb");
	if(fp_hs_in != NULL) {
		FILE* fp_hs_out = fopen("output/HTTPAServer", "ab");
		printf("Found %d occurrences in HTTPAServer.\n", convert(fp_hs_in, fp_hs_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_hs_out);
	}
	fclose(fp_hs_in);
	//LoginServer
	FILE* fp_ls_in = fopen("input/LoginServer", "rb");
	if(fp_ls_in != NULL) {
		FILE* fp_ls_out = fopen("output/LoginServer", "ab");
		printf("Found %d occurrences in LoginServer.\n", convert(fp_ls_in, fp_ls_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_ls_out);
	}
	fclose(fp_ls_in);
	//MissionServer
	FILE* fp_ms_in = fopen("input/MissionServer", "rb");
	if(fp_ms_in != NULL) {
		FILE* fp_ms_out = fopen("output/MissionServer", "ab");
		printf("Found %d occurrences in MissionServer.\n", convert(fp_ms_in, fp_ms_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_ms_out);
	}
	fclose(fp_ms_in);
	//TicketServer
	FILE* fp_ts_in = fopen("input/TicketServer", "rb");
	if(fp_ts_in != NULL) {
		FILE* fp_ts_out = fopen("output/TicketServer", "ab");
		printf("Found %d occurrences in TicketServer.\n", convert(fp_ts_in, fp_ts_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_ts_out);
	}
	fclose(fp_ts_in);
	//WorldServer
	FILE* fp_ws_in = fopen("input/WorldServer", "rb");
	if(fp_ws_in != NULL) {
		FILE* fp_ws_out = fopen("output/WorldServer", "ab");
		counter = convert(fp_ws_in, fp_ws_out, pattern, sizeof(pattern) / sizeof(int), replace_ip);
		if(counter != 0) {
			printf("Found %d occurrences in WorldServer.\n", counter);
		}
		fclose(fp_ws_out);
		if(counter == 0) {
			remove("output/WorldServer");
			fclose(fp_ws_in);
			fp_ws_in = fopen("input/WorldServer", "rb");
			fp_ws_out = fopen("output/WorldServer_1", "ab");
			counter = convert(fp_ws_in, fp_ws_out, crus_pattern_w1, sizeof(crus_pattern_w1) / sizeof(int), replace_ip);
			fclose(fp_ws_in);
			fclose(fp_ws_out);
			fp_ws_in = fopen("output/WorldServer_1", "rb");
			fp_ws_out = fopen("output/WorldServer_2", "ab");
			counter += convert(fp_ws_in, fp_ws_out, crus_pattern_w2, sizeof(crus_pattern_w2) / sizeof(int), replace_ip);
			fclose(fp_ws_in);
			fclose(fp_ws_out);
			fp_ws_in = fopen("output/WorldServer_2", "rb");
			fp_ws_out = fopen("output/WorldServer", "ab");
			counter += convert(fp_ws_in, fp_ws_out, crus_pattern_w3, sizeof(crus_pattern_w3) / sizeof(int), replace_ip);
			printf("Found %d occurrences in WorldServer.\n", counter);
			fclose(fp_ws_out);
		}
	}
	fclose(fp_ws_in);
	//WorldServer101
	FILE* fp_ws1_in = fopen("input/WorldServer101", "rb");
	if(fp_ws1_in != NULL) {
		FILE* fp_ws1_out = fopen("output/WorldServer101", "ab");
		printf("Found %d occurrences in WorldServer101.\n", convert(fp_ws1_in, fp_ws1_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_ws1_out);
	}
	fclose(fp_ws1_in);
	//WorldServer102
	FILE* fp_ws2_in = fopen("input/WorldServer102", "rb");
	if(fp_ws2_in != NULL) {
		FILE* fp_ws2_out = fopen("output/WorldServer102", "ab");
		printf("Found %d occurrences in WorldServer102.\n", convert(fp_ws2_in, fp_ws2_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_ws2_out);
	}
	fclose(fp_ws2_in);
	//ZoneServer
	FILE* fp_zs_in = fopen("input/ZoneServer", "rb");
	if(fp_zs_in != NULL) {
		FILE* fp_zs_out = fopen("output/ZoneServer", "ab");
		counter = convert(fp_zs_in, fp_zs_out, pattern, sizeof(pattern) / sizeof(int), replace_ip);
		if(counter != 0) {
			printf("Found %d occurrences in ZoneServer.\n", counter);
		}
		fclose(fp_zs_out);
		if(counter == 0) {
			remove("output/ZoneServer");
			fclose(fp_zs_in);
			fp_zs_in = fopen("input/ZoneServer", "rb");
			fp_zs_out = fopen("output/ZoneServer", "ab");
			counter = convert(fp_zs_in, fp_zs_out, crus_pattern_z, sizeof(crus_pattern_z) / sizeof(int), replace_ip);
			printf("Found %d occurrences in ZoneServer.\n", counter);
			fclose(fp_zs_out);
		}
	}
	fclose(fp_zs_in);
	//ZoneServer101
	FILE* fp_zs1_in = fopen("input/ZoneServer101", "rb");
	if(fp_zs1_in != NULL) {
		FILE* fp_zs1_out = fopen("output/ZoneServer101", "ab");
		printf("Found %d occurrences in ZoneServer101.\n", convert(fp_zs1_in, fp_zs1_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_zs1_out);
	}
	fclose(fp_zs1_in);
	//ZoneServer102
	FILE* fp_zs2_in = fopen("input/ZoneServer102", "rb");
	if(fp_zs2_in != NULL) {
		FILE* fp_zs2_out = fopen("output/ZoneServer102", "ab");
		printf("Found %d occurrences in ZoneServer102.\n", convert(fp_zs2_in, fp_zs2_out, pattern, sizeof(pattern) / sizeof(int), replace_ip));
		fclose(fp_zs2_out);
	}
	fclose(fp_zs2_in);
	//cleanup
	remove("output/WorldServer_1");
	remove("output/WorldServer_2");
	printf("\nDone... Press any key to quit.");
	fflush(stdin);
	getchar();
	return 0;
}

int convert(FILE* fp_in, FILE* fp_out, int search[], int size, int replace[]) {
	int curr_se = 0;
	int matches = 0;
	int point = 0;
	while((point = fgetc(fp_in)) != EOF) {
		if(point != search[curr_se]) {
			for(int i = 0; i < curr_se; i++) {
				fputc(search[i], fp_out);
			}
			curr_se = 0;
			fputc(point, fp_out);
		} else {
			curr_se++;
			if(curr_se == size) {
				for(int i = 0; i < size; i++) {
					putc(search[i], fp_out);
				}
				fgetc(fp_in);
				fputc(replace[0], fp_out);
				fgetc(fp_in);
				fputc(replace[1], fp_out);
				fgetc(fp_in);
				fputc(replace[2], fp_out);
				curr_se = 0;
				matches++;
			}
		}
	}
	for(int i = 0; i < curr_se; i++) {
		fputc(search[i], fp_out);
	}
	return matches;
}