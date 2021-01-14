////
//// Created by root on 1/14/21.
////
//
//#ifndef MD_OBJECTIVE_TEST_RK4INTEGRATOR_H
//#define MD_OBJECTIVE_TEST_RK4INTEGRATOR_H
//
//template<typename T, typename K>
//std::function<T(K)> RK4(const std::function<T(T, K)> &field, const T &y0, const K &t0, K stepsize) {
//    return [=](K t)mutable {
//
//        int n = (std::abs(t - t0) / stepsize) ; // normalize
//        if(n!=0)
//            stepsize = std::abs(t - t0) / n;
//
//        T ans = y0;
//        K ti = t0;
//        T K1, K2, K3, K4;
//        for (int i = 1; i <= n; ++i) {
//
//            K1 = stepsize * field(ans, ti);
//            K2 = stepsize * field(ans + 0.5 * K1, ti + 0.5 * stepsize);
//            K3 = stepsize * field(ans + 0.5 * K2, ti + 0.5 * stepsize);
//            K4 = stepsize * field(ans + K3, ti + stepsize);
//
//            ti += stepsize;   // ti = i*h + t0;
//            ans += (double(1) / 6) * (K1 + 2 * K2 + 2 * K3 + K4);
//        }
//
//        return ans;
//    };
//}
//template <typename T,typename K>
//std::function<Vector<double>(double)>
//RK4_second_order(const std::function<T(T, T, K)> &field, const T &yp0, const T &y0, const K &t0, K stepsize){
//    /*
//     *  y" = f(y',y,x) and yp(t0) = yp0 and y(t0) = t0
//     *  if we use these vector form:
//     *
//     *  | y(x) |                          | y'(x)|   | y'(x)    |
//     *  |      | = R  the we have   R'  = |      | = |          |   that is a linear ode and we can solve like RK4
//     *  | y'(x)|                          | y"(x)|   | f(y',y,x)|
//     *
//     *
//     *  its easy to see this beauty here:   R' = F(y',y,x) and we can even simplify with this R' = F(R,x)
//     *  now we can use standard RK4 but in vector form and remember we need to define vector addition and scaler multiplication
//     *  so in the rest of this function we will define Vector and use RK4 on it;
//     */
//
//
//    std::function<Vector<T>(Vector<T>,K)> reducedField = [=](Vector<T> v,K t){
//        return Vector<T>(v.y,field(v.y,v.x,t));   // R=[y,yp] so F = [yp,f(yp,y,x)] this is F definition
//    };
//    return RK4(reducedField,Vector<T>(y0,yp0),t0,stepsize);
//}
//
//
//#endif //MD_OBJECTIVE_TEST_RK4INTEGRATOR_H
