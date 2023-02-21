#include <iostream>
#include <fstream>

void write_to_file(const std::string fileName, const int* arr, const int arr_size) {
  std::ofstream wfile (fileName, std::ios_base::app);
  wfile << arr_size << "\n";
  for (int i = 0; i < arr_size; i++) {
    wfile << arr[i] << " ";
  }
  wfile << "\n";
  wfile.close();
}

int main() 
{ 
  int arr1_len, arr2_len;
  int arr_element;

  std::ifstream rfile("in.txt");

  if (rfile.is_open()) {
    rfile >> arr1_len;
    int* arr1 = new int[arr1_len];
    
    for (int i = 0; i < arr1_len; i++) {
      rfile >> arr_element;
      arr1[i] = arr_element;
    }

    rfile >> arr2_len;
    int* arr2 = new int[arr2_len];

    for (int i = 0; i < arr2_len; i++) {
      rfile >> arr_element;
      arr2[i] = arr_element;
    }

    int prev= arr2[0];
    int next;
    for(int i = 0; i < arr2_len-1; ++i)
    {
        next = arr2[i+1];
        arr2[i+1] = prev;
        prev = next;
    }
    arr2[0] = prev;

    prev= arr1[0];
    for(int i = arr1_len; i > 1; --i)
    {
        next = arr1[i-1];
        arr1[i-1] = prev;
        prev = next;
    }
    arr1[0] = prev;

    remove( "out.txt");

    write_to_file("out.txt", arr2, arr2_len);
    write_to_file("out.txt", arr1, arr1_len);

    rfile.close();
    
    delete[] arr1, arr2;
  }

  return 0; 
}

