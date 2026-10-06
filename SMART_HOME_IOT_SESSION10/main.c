#include <stdio.h>

int main() {
    struct DeviceBad {
        int deviceID;
        char deviceName;
        float voltage;
        int status;
        float current;
        char room;
        float power;
        int operatingMinutes;
    };

    struct DeviceOptimized {
        float voltage;
        float current;
        float power;
        int deviceID;
        int status;
        int operatingMinutes;
        char deviceName;
        char room;
    };

    struct DeviceBad oldDevice;
    struct DeviceOptimized device;

    float calculatedPower;
    float difference;
    float differencePercent;
    float energyKWh;


    printf("============================================\n");
    printf(" PHAN TICH MEMORY ALIGNMENT VA PADDING\n");
    printf("============================================\n");

    printf("Kich thuoc struct chua toi uu : %zu byte\n",
           sizeof(oldDevice));

    printf("Kich thuoc struct da toi uu   : %zu byte\n",
           sizeof(device));

    if (sizeof(device) < sizeof(oldDevice)) {
        printf("=> Struct da toi uu tiet kiem bo nho.\n");
    }else if (sizeof(device) == sizeof(oldDevice)) {
        printf("=> Hai struct co cung kich thuoc.\n");
    }else {
        printf("=> Struct da toi uu khong giam kich thuoc.\n");
    }

    printf("\n============================================\n");
    printf(" NHAP THONG TIN THIET BI\n");
    printf("============================================\n");

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ky tu ten thiet bi: ");
    scanf(" %c", &device.deviceName);

    printf("Nhap dien ap U (V): ");
    scanf("%f", &device.voltage);

    printf("Nhap dong dien I (A): ");
    scanf("%f", &device.current);

    printf("Nhap cong suat do duoc P (W): ");
    scanf("%f", &device.power);

    printf("Nhap trang thai (0-TAT, 1-BAT): ");
    scanf("%d", &device.status);

    printf("Nhap thoi gian hoat dong (phut): ");
    scanf("%d", &device.operatingMinutes);

    printf("Nhap ky tu phong: ");
    scanf(" %c", &device.room);

    if (device.voltage <= 0) {

        printf("\nLOI: Dien ap phai lon hon 0.\n");

    }else if (device.current < 0) {
        printf("\nLOI: Dong dien khong duoc am.\n");

    }else if (device.operatingMinutes < 0) {

        printf("\nLOI: Thoi gian hoat dong khong duoc am.\n");
    }else if (device.status != 0 && device.status != 1) {
        printf("\nLOI: Trang thai chi duoc la 0 hoac 1.\n");

    }else {

        calculatedPower = device.voltage * device.current;

        printf("\n============================================\n");
        printf(" KET QUA PHAN TICH\n");
        printf("============================================\n");
        printf("Cong suat do duoc    : %.2f W\n", device.power);
        printf("Cong suat tinh toan  : %.2f W\n", calculatedPower);

        difference = device.power - calculatedPower;

        if (difference < 0) { difference = -difference;
        }

        if (calculatedPower > 0) {
            differencePercent = (difference / calculatedPower) * 100.0f;

            printf("Do sai lech           : %.2f%%\n",  differencePercent);
            if (differencePercent > 5.0f) {
                printf("CANH BAO: Cam bien cong suat bao sai lech.\n");
            }else {
                printf("Cam bien cong suat hoat dong binh thuong.\n");
            }
        }

        if (device.current > 30.0f || device.power > 6600.0f) {
            printf("CANH BAO: QUA TAI NGUY HIEM.\n");

        } else {
            printf("Trang thai tai: AN TOAN.\n");
        }

        if (device.status == 0 && device.current > 0.05f) {
            printf("CANH BAO: RO RI DIEN HOAC TAI AN.\n");

        } else {
            printf("Khong phat hien ro ri dien.\n");
        }
        energyKWh = device.power * (device.operatingMinutes / 60.0f) / 1000.0f;

        printf("\nDien nang tieu thu: %.4f kWh\n", energyKWh);
        printf("\n============================================\n");
        printf(" THONG TIN THIET BI\n");
        printf("============================================\n");
        printf("Ma thiet bi       : %d\n", device.deviceID);
        printf("Ten thiet bi      : %c\n", device.deviceName);
        printf("Phong             : %c\n", device.room);
        printf("Trang thai        : %s\n", device.status == 1 ? "BAT" : "TAT");
        printf("Dien ap           : %.2f V\n", device.voltage);
        printf("Dong dien         : %.2f A\n", device.current);
        printf("Cong suat         : %.2f W\n",device.power);
        printf("Thoi gian         : %d phut\n", device.operatingMinutes);
        printf("Dien nang         : %.4f kWh\n",energyKWh);

        printf("============================================\n");
    }

    return 0;
}