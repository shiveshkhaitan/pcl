#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <Eigen/SVD>
#include <Eigen/StdVector>
#include <Eigen/src/StlSupport/details.h>
#include <algorithm>
#include <alloca.h>
#include <array>
#include <bitset>
#include <boost/algorithm/string.hpp>
#include <boost/cstdint.hpp>
#include <boost/current_function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/foreach.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/filter_if.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/sequence/intrinsic/at_key.hpp>
#include <boost/make_shared.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/aux_/unwrap.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/filter_view.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/next_prior.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/predef/other/endian.h>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison.hpp>
#include <boost/preprocessor/expand.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_product.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>
#include <boost/preprocessor/seq/transform.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signals2.hpp>
#include <boost/signals2/slot.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <cfloat>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstdarg>
#include <cstddef>
#include <cstddef> //offsetof
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <emmintrin.h> // SSE2:<e*.h>, SSE3:<p*.h>, SSE4:<s*.h>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <iostream>
#include <limits.h>
#include <limits>
#include <locale>
#include <map>
#include <math.h>
#include <mutex>
#include <numeric>
#include <ostream>
#include <pcl/ModelCoefficients.h>
#include <pcl/PCLHeader.h>
#include <pcl/PCLImage.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/PCLPointField.h>
#include <pcl/PointIndices.h>
#include <pcl/PolygonMesh.h>
#include <pcl/Vertices.h>
#include <pcl/cloud_iterator.h>
#include <pcl/common/angles.h>
#include <pcl/common/bivariate_polynomial.h>
#include <pcl/common/centroid.h>
#include <pcl/common/common.h>
#include <pcl/common/common_headers.h>
#include <pcl/common/concatenate.h>
#include <pcl/common/copy_point.h>
#include <pcl/common/distances.h>
#include <pcl/common/eigen.h>
#include <pcl/common/fft/kiss_fft.h>
#include <pcl/common/file_io.h>
#include <pcl/common/gaussian.h>
#include <pcl/common/generate.h>
#include <pcl/common/impl/accumulators.hpp>
#include <pcl/common/impl/angles.hpp>
#include <pcl/common/impl/bivariate_polynomial.hpp>
#include <pcl/common/impl/centroid.hpp>
#include <pcl/common/impl/common.hpp>
#include <pcl/common/impl/copy_point.hpp>
#include <pcl/common/impl/eigen.hpp>
#include <pcl/common/impl/file_io.hpp>
#include <pcl/common/impl/gaussian.hpp>
#include <pcl/common/impl/generate.hpp>
#include <pcl/common/impl/intensity.hpp>
#include <pcl/common/impl/intersections.hpp>
#include <pcl/common/impl/io.hpp>
#include <pcl/common/impl/norms.hpp>
#include <pcl/common/impl/pca.hpp>
#include <pcl/common/impl/piecewise_linear_function.hpp>
#include <pcl/common/impl/polynomial_calculations.hpp>
#include <pcl/common/impl/projection_matrix.hpp>
#include <pcl/common/impl/random.hpp>
#include <pcl/common/impl/spring.hpp>
#include <pcl/common/impl/transformation_from_correspondences.hpp>
#include <pcl/common/impl/transforms.hpp>
#include <pcl/common/impl/vector_average.hpp>
#include <pcl/common/intensity.h>
#include <pcl/common/intersections.h>
#include <pcl/common/io.h>
#include <pcl/common/norms.h>
#include <pcl/common/pca.h>
#include <pcl/common/piecewise_linear_function.h>
#include <pcl/common/point_tests.h>
#include <pcl/common/polynomial_calculations.h>
#include <pcl/common/projection_matrix.h>
#include <pcl/common/random.h>
#include <pcl/common/spring.h>
#include <pcl/common/time.h>
#include <pcl/common/transformation_from_correspondences.h>
#include <pcl/common/transforms.h>
#include <pcl/common/vector_average.h>
#include <pcl/console/print.h>
#include <pcl/conversions.h>
#include <pcl/correspondence.h>
#include <pcl/exceptions.h>
#include <pcl/for_each_type.h>
#include <pcl/impl/cloud_iterator.hpp>
#include <pcl/impl/pcl_base.hpp>
#include <pcl/impl/point_types.hpp>  // Include struct definitions
#include <pcl/make_shared.h>
#include <pcl/pcl_base.h>
#include <pcl/pcl_config.h>
#include <pcl/pcl_exports.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_traits.h>
#include <pcl/point_types.h>
#include <pcl/range_image/impl/range_image.hpp>  // Definitions of templated and inline functions
#include <pcl/range_image/impl/range_image_planar.hpp>  // Definitions of templated and inline functions
#include <pcl/range_image/impl/range_image_spherical.hpp>  // Definitions of templated and inline functions
#include <pcl/range_image/range_image.h>
#include <pcl/range_image/range_image_planar.h>
#include <pcl/range_image/range_image_spherical.h>
#include <pcl/register_point_struct.h>
#include <queue>
#include <random>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <thread>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <vector>
#include <xmmintrin.h>
