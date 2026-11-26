# DesktopUIT

Bài tập Chương 3 về lập trình hướng đối tượng bằng C++, minh họa cách quản lý danh sách thí sinh.

- `Candidate.h` và `Candidate.cpp` định nghĩa lớp lưu thông tin thí sinh.
- `KhoaHoc.h` và `KhoaHoc.cpp` quản lý danh sách thí sinh, kiểm tra mã trùng, tìm kiếm, sắp xếp và xóa thí sinh.
- `main.cpp` chạy các thao tác trên dữ liệu mẫu.

## Biên dịch và chạy

Mở Terminal trong thư mục chứa mã nguồn, rồi chạy:

```bash
clang++ -std=c++17 main.cpp Candidate.cpp KhoaHoc.cpp -o DesktopUIT
./DesktopUIT
```

Chương trình tự chạy với dữ liệu mẫu và in kết quả từng thao tác ra Terminal.
