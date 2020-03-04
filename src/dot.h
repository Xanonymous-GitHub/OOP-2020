double dot(double u[], int dim_u, double v[], int dim_v) {
    double result = 0;
    for (int i = 0; i < dim_u; i++) {
        result += u[i] * v[i];
    }
    return result;
}