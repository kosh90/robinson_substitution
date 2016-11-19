#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fsubs.h"


int main()
{
    int n;
    int m;
    int tmp;
    int pos[2] = { 0, 0 };


    std::string name;
    std::string namejs;
    std::string inputname;
    std::string outputname;
    std::string tmpstr;

    name   = "super_order_";
    namejs = "super";

    // std::string outputfilename


    std::cout << "enter n, please" << std::endl;
    std::cout << "super tile of order n must exist" << std::endl;
    std::cout << "2^2-1=3, so it is better to star with n = 2" << std::endl;

    std::cin >> n;
    std::string buf = std::to_string(n);
    inputname  = name + buf + ".txt";
    buf        = std::to_string(n + 1);
    outputname = name + buf + ".txt";
		name = name + buf;


    m = myPow(2, n + 1) - 1;
    n = myPow(2, n) - 1;
    std::cout << "n, m: " << n << ", " << m << std::endl;

    std::cout << "lookin for  " << inputname << std::endl;

    std::ifstream inputfile(inputname);

    if (inputfile.is_open())
        std::cout << inputname << " is opened" << std::endl;
    else
    {
        std::cout << "file not found" << std::endl;
        return 0;
    }

    buf = std::to_string(m);

    std::ofstream outputfile(outputname);

    if (outputfile.is_open())
        std::cout << outputname << " is opened" << std::endl;
    else
    {
        std::cout << "output error!" << std::endl;
        return 0;
    }

    typedef std::vector<int>   Row;
    typedef std::vector<Row>   Matrix;

    Matrix in_matrix(n, Row(n));
    Matrix out_matrix(m, Row(m));

    std::cout << "size if in_matrix is " << in_matrix.size() << std::endl;
    std::cout << "size if out_matrix is " << out_matrix.size() << std::endl;
    std::cout << std::endl;







    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            out_matrix[i][j] = -1;
        }
    }


//----------------------------------------------------------------


    while (getMartix(in_matrix, inputfile))
    {
        std::cout << "printing input martix:" << std::endl;
        // printMatrix(in_matrix);
        // std::cout << "(pos_x,pos_y) =" << pos[0] << ", " << pos[1] << std::endl;



        for (int i = 0; i < in_matrix.size(); i++)
        {
            for (int j = 0; j < in_matrix.size(); j++)
            {
                // n = find_next_pos(out_matrix, pos);
                substitute(i, j, in_matrix, out_matrix, pos);
                // std::cout << "(pos_x,pos_y) =" << pos[0] << ", " << pos[1] << std::endl;
                // std::cout << out_matrix[pos[0]][pos[1]] << std::endl;
                // printMatrix(out_matrix);
                // std::cin >> tmpstr;
            }
        }
        std::cout << "printing" << std::endl;
        printMatrix(out_matrix);
        std::cout << "add to file" << std::endl;
        addMatrixToFile(out_matrix, outputfile);
				// write_2dvector_to_js(out_matrix, name);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                out_matrix[i][j] = -1;
            }
        }
        pos[0] = 0;
        pos[1] = 0;
    }

//----------------------------------------------------------------
    // std::cout << "printing result:" << std::endl;
    // printMatrix(out_matrix);
    // write_2dvector_to_file(out_matrix, name);
    // write_2dvector_to_js(out_matrix, namejs);


    inputfile.close();
    outputfile.close();


    return 0;
}
