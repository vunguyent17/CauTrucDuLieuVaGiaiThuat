#pragma once
#include <iostream>

using namespace std;

struct DonThuc{
    float heso;
    int somu;
};

struct DaThuc{
    DonThuc A[50];
    int so_don_thuc;
    int bac;
};

// 3a. Nhap/Xuat da thuc
DonThuc NhapDonThuc(){
    DonThuc ket_qua;
    cout << "\tNhap he so: ";
    cin >> ket_qua.heso;
    cout << "\tNhap so mu: ";
    cin >> ket_qua.somu;
    return ket_qua;
}

void XuatDonThuc(DonThuc so_hang){
    cout << so_hang.heso << "x" << so_hang.somu;
}

void NhapDaThuc(DaThuc &da_thuc){
    DonThuc temp;
    //int so_don_thuc;
    int so_phan_tu_trung;
    int vi_tri_dung = 0;
    int flag;
    so_phan_tu_trung = 0;
    cout << "Nhap so luong don thuc: ";
    cin >> da_thuc.so_don_thuc;

    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        flag = 1;
        cout << "So hang thu " << i + 1 << ": " << endl;
        temp = NhapDonThuc();
        // Kiem tra cac don thuc da nhap
        for (int j=0; j<vi_tri_dung; j++){
            // Neu so mu da co, thay doi so hang
            if (da_thuc.A[j].somu == temp.somu)
            {
                da_thuc.A[j].heso += temp.heso;
                so_phan_tu_trung++;
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            da_thuc.A[vi_tri_dung] = temp;
            vi_tri_dung++;
        }
    }
    da_thuc.so_don_thuc -= so_phan_tu_trung;
}

void XuatDaThuc(DaThuc da_thuc){
    cout << "P(x) = ";
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        XuatDonThuc(da_thuc.A[i]);
        if (i != da_thuc.so_don_thuc - 1){
            cout << " + ";
        }
    }
    cout << endl;
}

// 3b. Tim bac da thuc, Sap xep da thuc
void SapXepDaThuc(DaThuc &da_thuc){
    DonThuc temp;
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        temp = da_thuc.A[i];
        for (int j = i; j < da_thuc.so_don_thuc; j++)
        {
            if (da_thuc.A[j].somu > da_thuc.A[i].somu){
                da_thuc.A[i] = da_thuc.A[j];
                da_thuc.A[j] = temp;
                temp = da_thuc.A[i];
            }
        }    
    }
    da_thuc.bac = da_thuc.A[0].somu;
}

// 3c. Tinh gia tri da thuc
int TinhLuyThua(int x, int so_mu){
    int ket_qua;
    ket_qua = 1;
    for (int i = 0; i < so_mu; i++){
        ket_qua *= x;
    }
    return ket_qua;
}

float TinhGiaTriDaThuc(DaThuc da_thuc, int x){
    float gia_tri;
    float he_so;
    int so_mu;
    gia_tri = 0;
    for (int i = 0; i < da_thuc.so_don_thuc; i++){
        he_so = da_thuc.A[i].heso;
        so_mu = da_thuc.A[i].somu;
        gia_tri += he_so * TinhLuyThua(x, so_mu);
    }
    return gia_tri;    
}

// 3d. Cong, tru, nhan 2 da thuc
DaThuc CongDaThuc(DaThuc A, DaThuc B)
{    
    DaThuc kq;
    DonThuc temp;
    int vi_tri_dung;
    int so_phan_tu_trung;
    int flag;
    SapXepDaThuc(A);
    SapXepDaThuc(B);
    vi_tri_dung = 0;
    kq.so_don_thuc = A.so_don_thuc + B.so_don_thuc;
    for (int i=0; i<A.so_don_thuc; i++)
    {
        kq.A[i] = A.A[i];
        vi_tri_dung++;
    }
    so_phan_tu_trung = 0;
    for (int i=0; i<B.so_don_thuc; i++)
    {
        flag = 1;
        temp = B.A[i];
        // Kiem tra cac don thuc da nhap
        for (int j=0; j<vi_tri_dung; j++){
            // Neu so mu da co, thay do he so
            if (kq.A[j].somu == temp.somu)
            {
                kq.A[j].heso += temp.heso;
                so_phan_tu_trung++;
                flag = 0;
                break;
            }

        }
        if (flag)
        {
            kq.A[vi_tri_dung] = temp;
            vi_tri_dung++;
        }
    }
    kq.so_don_thuc -= so_phan_tu_trung;
    SapXepDaThuc(kq);
    return kq;
}

DaThuc TruDaThuc(DaThuc A, DaThuc B)
{    
    DaThuc kq;
    DonThuc temp;
    int vi_tri_dung;
    int so_phan_tu_trung;
    int flag;
    SapXepDaThuc(A);
    SapXepDaThuc(B);
    vi_tri_dung = 0;
    kq.so_don_thuc = A.so_don_thuc + B.so_don_thuc;
    for (int i=0; i<A.so_don_thuc; i++)
    {
        kq.A[i] = A.A[i];
        vi_tri_dung++;
    }
    so_phan_tu_trung = 0;
    for (int i=0; i<B.so_don_thuc; i++)
    {
        flag = 1;
        temp = B.A[i];
        // Kiem tra cac don thuc da nhap
        for (int j=0; j<vi_tri_dung; j++){
            // Neu so mu da co, thay do he so
            if (kq.A[j].somu == temp.somu)
            {
                kq.A[j].heso -= temp.heso;
                so_phan_tu_trung++;
                flag = 0;
                break;
            }

        }
        if (flag)
        {
            kq.A[vi_tri_dung] = temp;
            vi_tri_dung++;
        }
    }
    kq.so_don_thuc -= so_phan_tu_trung;
    SapXepDaThuc(kq);
    return kq;
}

DaThuc NhanDaThuc(DaThuc A, DaThuc B)
{    
    DaThuc kq;
    DonThuc temp;
    int vi_tri_dung;
    int so_phan_tu_trung = 0;
    int flag;
    vi_tri_dung = 0;
    kq.so_don_thuc = A.so_don_thuc * B.so_don_thuc;
    for (int i=0; i<A.so_don_thuc; i++)
    {
        temp = A.A[i];
        for (int j=0; j<B.so_don_thuc; j++)
        {
            temp.heso = A.A[i].heso * B.A[j].heso;
            temp.somu = A.A[i].somu + B.A[j].somu;
            kq.A[vi_tri_dung] = temp;
            vi_tri_dung++;
        }
    }
    vi_tri_dung = 0;
    for (int k=0; k<kq.so_don_thuc; k++)
    {
        flag = 1;
        temp = kq.A[k];
        // Kiem tra cac don thuc da nhap
        for (int j=0; j<vi_tri_dung; j++){
            // Neu so mu da co, thay do he so
            if (kq.A[j].somu == temp.somu)
            {
                kq.A[j].heso += temp.heso;
                so_phan_tu_trung++;
                flag = 0;
                break;
            }

        }
        if (flag)
        {
            kq.A[vi_tri_dung] = temp;
            vi_tri_dung++;
        }
    }
    kq.so_don_thuc = vi_tri_dung;
    SapXepDaThuc(kq);
    return kq;
}
