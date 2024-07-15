#include <stdio.h>
#include <string.h>

#define MAX_PROJECTS 100

typedef struct {
    char maDeTai[10];
    char tenDeTai[100];
    char loaiDeTai[50];
    char hoTenNguoi[50];
    float kinhPhi;
} DeTai;

DeTai danhSachDeTai[MAX_PROJECTS];
int soLuongDeTai = 0;

void nhapThongTinDeTai() {
    if (soLuongDeTai >= MAX_PROJECTS) {
        printf("Danh sach de tai da day!\n");
        return;
    }

    DeTai dt;
    printf("Nhap ma de tai: ");
    scanf("%s", dt.maDeTai);
    printf("Nhap ten de tai: ");
    scanf(" %[^\n]%*c", dt.tenDeTai);
    printf("Nhap loai de tai: ");
    scanf(" %[^\n]%*c", dt.loaiDeTai);
    printf("Nhap ho ten nguoi: ");
    scanf(" %[^\n]%*c", dt.hoTenNguoi);
    printf("Nhap kinh phi: ");
    scanf("%f", &dt.kinhPhi);

    danhSachDeTai[soLuongDeTai++] = dt;
}

void suaKinhPhi() {
    char maDeTai[10];
    printf("Nhap ma de tai can sua: ");
    scanf("%s", maDeTai);
	
	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        if (strcmp(danhSachDeTai[i].maDeTai, maDeTai) == 0) {
            printf("Nhap kinh phi moi: ");
            scanf("%f", &danhSachDeTai[i].kinhPhi);
            printf("Da cap nhat kinh phi!\n");
            return;
        }
    }
    printf("Khong tim thay de tai voi ma: %s\n", maDeTai);
}

void suaTenNguoi() {
    char maDeTai[10];
    printf("Nhap ma de tai can sua: ");
    scanf("%s", maDeTai);
	
	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        if (strcmp(danhSachDeTai[i].maDeTai, maDeTai) == 0) {
            printf("Nhap ten nguoi moi: ");
            scanf(" %[^\n]%*c", danhSachDeTai[i].hoTenNguoi);
            printf("Da cap nhat ten nguoi chu nhiem!\n");
            return;
        }
    }
    printf("Khong tim thay de tai voi ma: %s\n", maDeTai);
}

void xoaDeTai() {
    char maDeTai[10];
    printf("Nhap ma de tai can xoa: ");
    scanf("%s", maDeTai);
	
	int i,j; 
    for ( i = 0; i < soLuongDeTai; i++) {
        if (strcmp(danhSachDeTai[i].maDeTai, maDeTai) == 0) {
            for ( j = i; j < soLuongDeTai - 1; j++) {
                danhSachDeTai[j] = danhSachDeTai[j + 1];
            }
            soLuongDeTai--;
            printf("Da xoa de tai!\n");
            return;
        }
    }
    printf("Khong tim thay de tai voi ma: %s\n", maDeTai);
}
//Ham so sanh va sap xep
int compareLoaiDeTai(const void *a, const void *b) {
    return strcmp(((DeTai*)b)->loaiDeTai, ((DeTai*)a)->loaiDeTai);
}
//Ham compare Kinh Phi
int compareKinhPhi(const void *a, const void *b) {
    if (((DeTai*)a)->kinhPhi > ((DeTai*)b)->kinhPhi) return 1;
    if (((DeTai*)a)->kinhPhi < ((DeTai*)b)->kinhPhi) return -1;
    return 0;
}
//Ham sap xep
void sapXepGiamDanTheoLoai() {
    qsort(danhSachDeTai, soLuongDeTai, sizeof(DeTai), compareLoaiDeTai);
    printf("Da sap xep giam dan theo loai de tai!\n");
}
//Ham sap xep Tang Dan Theo Kinh Phi
void sapXepTangDanTheoKinhPhi() {
    qsort(danhSachDeTai, soLuongDeTai, sizeof(DeTai), compareKinhPhi);
    printf("Da sap xep tang dan theo kinh phi!\n");
}
//Ham xuat Danh Sach
void xuatDanhSach() {
	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        printf("Ma: %s, Ten: %s, Loai: %s, Ho ten: %s, Kinh phi: %.2f\n", 
               danhSachDeTai[i].maDeTai, danhSachDeTai[i].tenDeTai, 
               danhSachDeTai[i].loaiDeTai, danhSachDeTai[i].hoTenNguoi, 
               danhSachDeTai[i].kinhPhi);
    }
}
//Ham xuat Danh Sach theo ma de tai
void xuatDanhSachTheoMaDeTai() {
    char maDeTai[10];
    printf("Nhap ma de tai: ");
    scanf("%s", maDeTai);
	
	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        if (strcmp(danhSachDeTai[i].maDeTai, maDeTai) == 0) {
            printf("Ma: %s, Ten: %s, Loai: %s, Ho ten: %s, Kinh phi: %.2f\n", 
                   danhSachDeTai[i].maDeTai, danhSachDeTai[i].tenDeTai, 
                   danhSachDeTai[i].loaiDeTai, danhSachDeTai[i].hoTenNguoi, 
                   danhSachDeTai[i].kinhPhi);
        }
    }
}
//Ham xuat danh sach theo kinh phi trong khoang
void xuatDanhSachTheoKinhPhiTrongKhoang() {
    float minKinhPhi, maxKinhPhi;
    printf("Nhap khoang kinh phi (min max): ");
    scanf("%f %f", &minKinhPhi, &maxKinhPhi);

	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        if (danhSachDeTai[i].kinhPhi >= minKinhPhi && danhSachDeTai[i].kinhPhi <= maxKinhPhi) {
            printf("Ma: %s, Ten: %s, Loai: %s, Ho ten: %s, Kinh phi: %.2f\n", 
                   danhSachDeTai[i].maDeTai, danhSachDeTai[i].tenDeTai, 
                   danhSachDeTai[i].loaiDeTai, danhSachDeTai[i].hoTenNguoi, 
                   danhSachDeTai[i].kinhPhi);
        }
    }
}
//ham xuat thong ke kinh phi
void xuatThongKeKinhPhi() {
    if (soLuongDeTai == 0) {
        printf("Khong co de tai nao!\n");
        return;
    }

    float tongKinhPhi = 0;
    float maxKinhPhi = danhSachDeTai[0].kinhPhi;
    float minKinhPhi = danhSachDeTai[0].kinhPhi;
	
	int i; 
    for ( i = 0; i < soLuongDeTai; i++) {
        tongKinhPhi += danhSachDeTai[i].kinhPhi;
        if (danhSachDeTai[i].kinhPhi > maxKinhPhi) {
            maxKinhPhi = danhSachDeTai[i].kinhPhi;
        }
        if (danhSachDeTai[i].kinhPhi < minKinhPhi) {
            minKinhPhi = danhSachDeTai[i].kinhPhi;
        }
    }

    float trungBinhKinhPhi = tongKinhPhi / soLuongDeTai;

    printf("Kinh phi trung binh: %.2f\n", trungBinhKinhPhi);
    printf("Kinh phi cao nhat: %.2f\n", maxKinhPhi);
    printf("Kinh phi thap nhat: %.2f\n", minKinhPhi);
}
//
void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Nhap thong tin De tai\n");
        printf("2. Sua kinh phi De tai\n");
        printf("3. Sua ten nguoi chu nhiem\n");
        printf("4. Xoa De tai\n");
        printf("5. Sap xep giam dan theo Loai De tai\n");
        printf("6. Sap xep tang dan theo Kinh phi\n");
        printf("7. Xuat toan bo danh sach\n");
        printf("8. Xuat danh sach theo Ma De tai\n");
        printf("9. Xuat danh sach theo Kinh phi trong khoang\n");
        printf("10. Xuat kinh phi trung binh, cao nhat, thap nhat\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinDeTai();
                break;
            case 2:
                suaKinhPhi();
                break;
            case 3:
                suaTenNguoi();
                break;
            case 4:
                xoaDeTai();
                break;
            case 5:
                sapXepGiamDanTheoLoai();
                break;
            case 6:
                sapXepTangDanTheoKinhPhi();
                break;
            case 7:
                xuatDanhSach();
                break;
            case 8:
                xuatDanhSachTheoMaDeTai();
                break;
            case 9:
                xuatDanhSachTheoKinhPhiTrongKhoang();
                break;
            case 10:
                xuatThongKeKinhPhi();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}

