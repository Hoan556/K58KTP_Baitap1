# K58KTP_Baitap1
Nội dung bài tập 1
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN

Caesar
Affine
Hoán vị
Vigenère
Playfair
Với mỗi phương pháp, hãy tìm hiểu:

Tên gọi
Thuật toán mã hoá, thuật toán giải mã
Không gian khóa
Cách phá mã (mà không cần khoá)
Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
  ## Bài làm 
  # 1 Caesar cipher
Tên gọi

Caesar cipher (mã Caesar) — dịch chữ theo một dịch chuyển cố định.

Thuật toán

Mã hoá: với khóa k (0..25), với mỗi ký tự chữ cái P (0..25):
C = (P + k) mod 26.

Giải mã: P = (C - k mod 26 + 26) mod 26.

Không gian khóa

26 khả năng (k = 0..25).

Cách phá (không cần khóa)

Brute-force: thử tất cả 26 khả năng; nhanh và đơn giản.

Phân tích tần suất: tần suất chữ cái (E, T, A, O...) có thể giúp chọn dịch chuyển đúng.
C++ (console)
* kết quả
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/5a633900-43bf-4746-abad-c621a84c43cf" />
### HTML+CSS+JS (single-file)
* kết quả
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/5e8177cb-9835-4ee2-9efb-444c5d77b156" />

# 2 Affine cipher
Tên gọi

Affine cipher — ánh xạ affine trên modulo 26: E(x) = (a*x + b) mod 26.

Thuật toán

Chọn a và b với gcd(a,26)=1 (để có nghịch đảo).

Mã hoá: C = (a * P + b) mod 26.

Giải mã: cần a^{-1} modulo 26 (số a_inv sao cho a * a_inv ≡ 1 (mod 26)), rồi P = a_inv * (C - b) mod 26.

Không gian khóa

a có 12 lựa chọn (số nguyên tố với 26): {1,3,5,7,9,11,15,17,19,21,23,25}. b có 26 lựa chọn ⇒ tổng 12 * 26 = 312 khóa.

Cách phá (không cần khóa)

Brute-force: thử 312 khả năng — rất thực tế.

Phân tích tần suất: vì là affine, ánh xạ là tuyến tính, tần suất vẫn dịch/hoán vị theo affine; đôi khi có thể suy a và b từ hai chữ cái phổ biến (ví dụ map 'E'→most frequent, 'T'→2nd frequent) và giải phương trình tuyến tính mod 26.
* kết quả
* 
 ### HTML+CSS+JS
 * kết quả 
