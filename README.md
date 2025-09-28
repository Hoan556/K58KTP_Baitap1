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
C++ (console)
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/bfad4e15-d4d5-4561-a9b9-70f65bfb2a8f" />

 ### HTML+CSS+JS
 * kết quả
 * <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/1d29b94d-42b7-4c34-af09-bd35fb1896ba" />

 # 3 Hoán vị (Permutation cipher) — Columnar transposition (một dạng phổ biến)

Ở đây mình triển khai Columnar transposition: sắp xếp cột theo khóa (một hoán vị).

Tên gọi

Columnar transposition (mã hoán vị cột) — đặt plaintext thành bảng theo số cột = chiều dài khóa, rồi đọc theo thứ tự cột được số hoá bởi khóa.

Thuật toán

Mã hoá:

Chọn khóa là một chuỗi ký tự không lặp (hoặc có thể lặp, ta sẽ ánh xạ thành số bằng vị trí sắp xếp). Ví dụ khóa "ZEBRA" → vị trí thứ tự sắp xếp các chữ cái là [5,2,3,1,4] (tùy cách đánh số).

Viết plaintext theo hàng vào ma trận có n = len(key) cột (thêm ký tự điền nếu cần).

Đọc các cột theo thứ tự tăng dần của số khóa và nối lại => ciphertext.

Giải mã:

Biết n, tính số hàng (ceil), dựa vào độ dài ciphertext biết số ô trống ở cột cuối; điền cột theo thứ tự khóa rồi đọc theo hàng.

Không gian khóa

Nếu giả sử khóa là một hoán vị độ dài n thì không gian khóa là n! (giai thừa). Với n=6 → 720 khóa; n=10 → ~3.6M.

Cách phá (không cần khóa)

Brute-force: thử mọi hoán vị (không khả thi nếu n lớn).

Phân tích cấu trúc: đo lường tính hợp lý của các cặp chữ, tần suất n-gram khi dựng lại; dùng heuristics (simulated annealing, hill-climbing) để tìm hoán vị tốt nhất (dùng scoring theo ngôn ngữ).

Nếu plaintext có cấu trúc rõ (ví dụ tiếng Anh) thì có thể đo IC (Index of coincidence) và các truy vấn heuristic.

C++ (console) — Columnar transposition
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/45f5d0bc-c061-4829-aed5-898c939797e6" />
# HTML+CSS+JS
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b107e084-e918-4da5-9ad8-1054cfd4b1a7" />
# 4 Vigenère cipher
Tên gọi

Vigenère cipher — "polyalphabetic substitution" sử dụng chuỗi khóa lặp.

Thuật toán

Mã hoá: với khóa chuỗi K = k0 k1 ... k(m-1) (mỗi ki trong 0..25), plaintext P dài L:
C[i] = (P[i] + K[i mod m]) mod 26.

Giải mã: P[i] = (C[i] - K[i mod m] + 26) mod 26.

Không gian khóa

Nếu khóa là chuỗi độ dài m, keyspace = 26^m. (Nếu không biết m, keyspace lớn.)

Cách phá (không cần khóa)

Kasiski examination: tìm khoảng cách giữa các mẫu trùng lặp để suy ra độ dài khóa m.

Friedman test (IC): ước lượng m bằng Index of Coincidence.

Sau khi biết m, tách ciphertext thành m luồng (mỗi luồng là Caesar cipher) và dùng phân tích tần suất (chi-square) để tìm dịch chuyển cho từng luồng.

Ngoài ra có thể dùng đoán-ngôn ngữ + brute-force từng độ dài nhỏ.

C++ (console)
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/e2936cea-d7c8-4723-ae61-7b31d445e10b" />
# HTML+CSS+JS
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/6d946cfb-7063-439b-ad52-665f9e535ae5" />
# 5Playfair cipher
Tên gọi

Playfair cipher — mã thay thế theo cặp chữ (digraph), dùng ma trận 5×5.

Chuẩn (thông dụng)

Dùng bảng 5×5 chứa 25 chữ cái (thường gộp I và J).

Tạo bảng từ khóa: viết khóa (loại bỏ chữ lặp), sau đó viết phần còn lại của bảng theo thứ tự A..Z (bỏ J).

Chia plaintext thành các cặp (digraph). Nếu một cặp có hai chữ cái giống nhau, chèn ký tự filler ('X' thường dùng) giữa chúng rồi tái phân chia. Nếu cuối cùng còn 1 chữ, thêm filler.

Với cặp (A,B):

Nếu A và B nằm cùng hàng: thay bằng kí tự bên phải (vòng)

Nếu cùng cột: thay bằng kí tự bên dưới (vòng)

Nếu khác hàng/cột: thay bằng hai ký tự ở góc của hình chữ nhật (A cùng hàng với B nhưng cột của B, và B cùng hàng với A nhưng cột của A).

Giải mã: làm ngược lại (bên trái / bên trên / dùng rectangle tương ứng).

Không gian khóa

Không gian rất lớn (bảng 5×5 sắp xếp 25 chữ cái): 25! / ? nhưng thực tế do ghi nhớ và ràng buộc (thứ tự từ khóa...) khả năng hiệu dụng rất lớn — khó brute force bằng tay, nhưng với máy có thể giảm bằng heuristics. Tuy nhiên Playfair có cấu trúc và bị tấn công bằng phân tích digraph.

Cách phá (không cần khóa)

Phân tích digraph: thống kê tần suất cặp 2 chữ cái (digraph) (không giống monoalphabetic) và so sánh với digraph thường gặp.

Hill-climbing / simulated annealing: coi bảng là trạng thái, thay đổi bảng để tối đa hóa điểm số dựa trên bigram/trigram frequency của ngôn ngữ.

Ký tự filler ('X') và quy tắc tách đôi cung cấp manh mối (ví dụ nhiều X đột biến).

 # C++ (console) — Playfair
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/0dca262b-8c83-4ed8-a3d9-a7a8693c189c" />
# HTML+CSS+JS
* kết quả
* <img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/bdea76b1-2f6e-4d6e-b3d4-eb5b954192d7" />






