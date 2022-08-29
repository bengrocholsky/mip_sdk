#pragma once

#include "descriptors.h"
#include "../mip_result.h"

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
namespace mip {
namespace C {
extern "C" {

#endif // __cplusplus
struct mip_interface;
struct mip_serializer;
struct mip_field;

////////////////////////////////////////////////////////////////////////////////
///@addtogroup MipData_c  MIP Data [C]
///@{
///@defgroup sensor_data_c  Sensor Data [C]
///
///@{

////////////////////////////////////////////////////////////////////////////////
// Descriptors
////////////////////////////////////////////////////////////////////////////////

enum 
{
    MIP_SENSOR_DATA_DESC_SET                            = 0x80,
    
    MIP_DATA_DESC_SENSOR_ACCEL_RAW                      = 0x01,
    MIP_DATA_DESC_SENSOR_GYRO_RAW                       = 0x02,
    MIP_DATA_DESC_SENSOR_MAG_RAW                        = 0x03,
    MIP_DATA_DESC_SENSOR_ACCEL_SCALED                   = 0x04,
    MIP_DATA_DESC_SENSOR_GYRO_SCALED                    = 0x05,
    MIP_DATA_DESC_SENSOR_MAG_SCALED                     = 0x06,
    MIP_DATA_DESC_SENSOR_DELTA_THETA                    = 0x07,
    MIP_DATA_DESC_SENSOR_DELTA_VELOCITY                 = 0x08,
    MIP_DATA_DESC_SENSOR_COMP_ORIENTATION_MATRIX        = 0x09,
    MIP_DATA_DESC_SENSOR_COMP_QUATERNION                = 0x0A,
    MIP_DATA_DESC_SENSOR_COMP_ORIENTATION_UPDATE_MATRIX = 0x0B,
    MIP_DATA_DESC_SENSOR_COMP_EULER_ANGLES              = 0x0C,
    MIP_DATA_DESC_SENSOR_TEMPERATURE_RAW                = 0x0D,
    MIP_DATA_DESC_SENSOR_TIME_STAMP_INTERNAL            = 0x0E,
    MIP_DATA_DESC_SENSOR_TIME_STAMP_PPS                 = 0x0F,
    MIP_DATA_DESC_SENSOR_STAB_MAG                       = 0x10,
    MIP_DATA_DESC_SENSOR_STAB_ACCEL                     = 0x11,
    MIP_DATA_DESC_SENSOR_TIME_STAMP_GPS                 = 0x12,
    MIP_DATA_DESC_SENSOR_TEMPERATURE_ABS                = 0x14,
    MIP_DATA_DESC_SENSOR_RAW_CLIP_DATA                  = 0x15,
    MIP_DATA_DESC_SENSOR_PRESSURE_RAW                   = 0x16,
    MIP_DATA_DESC_SENSOR_PRESSURE_SCALED                = 0x17,
    MIP_DATA_DESC_SENSOR_OVERRANGE_STATUS               = 0x18,
    MIP_DATA_DESC_SENSOR_ODOMETER                       = 0x40,
    
    MIP_DATA_DESC_ASPP                                  = 0x81,
    MIP_DATA_DESC_GXSB                                  = 0x82,
};

////////////////////////////////////////////////////////////////////////////////
// Shared Type Definitions
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Mip Fields
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_raw_accel  (0x80,0x01) Raw Accel [C]
/// Three element vector representing the sensed acceleration.
/// This quantity is temperature compensated and expressed in the sensor body frame.
///
///@{

struct mip_sensor_raw_accel_data
{
    float raw_accel[3]; ///< Native sensor counts
    
};
void insert_mip_sensor_raw_accel_data(struct mip_serializer* serializer, const struct mip_sensor_raw_accel_data* self);
void extract_mip_sensor_raw_accel_data(struct mip_serializer* serializer, struct mip_sensor_raw_accel_data* self);
bool extract_mip_sensor_raw_accel_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_raw_gyro  (0x80,0x02) Raw Gyro [C]
/// Three element vector representing the sensed angular rate.
/// This quantity is temperature compensated and expressed in the sensor body frame.
///
///@{

struct mip_sensor_raw_gyro_data
{
    float raw_gyro[3]; ///< Native sensor counts
    
};
void insert_mip_sensor_raw_gyro_data(struct mip_serializer* serializer, const struct mip_sensor_raw_gyro_data* self);
void extract_mip_sensor_raw_gyro_data(struct mip_serializer* serializer, struct mip_sensor_raw_gyro_data* self);
bool extract_mip_sensor_raw_gyro_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_raw_mag  (0x80,0x03) Raw Mag [C]
/// Three element vector representing the sensed magnetic field.
/// This quantity is temperature compensated and expressed in the vehicle frame.
///
///@{

struct mip_sensor_raw_mag_data
{
    float raw_mag[3]; ///< Native sensor counts
    
};
void insert_mip_sensor_raw_mag_data(struct mip_serializer* serializer, const struct mip_sensor_raw_mag_data* self);
void extract_mip_sensor_raw_mag_data(struct mip_serializer* serializer, struct mip_sensor_raw_mag_data* self);
bool extract_mip_sensor_raw_mag_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_raw_pressure  (0x80,0x16) Raw Pressure [C]
/// Scalar value representing the sensed ambient pressure.
/// This quantity is temperature compensated.
///
///@{

struct mip_sensor_raw_pressure_data
{
    float raw_pressure; ///< Native sensor counts
    
};
void insert_mip_sensor_raw_pressure_data(struct mip_serializer* serializer, const struct mip_sensor_raw_pressure_data* self);
void extract_mip_sensor_raw_pressure_data(struct mip_serializer* serializer, struct mip_sensor_raw_pressure_data* self);
bool extract_mip_sensor_raw_pressure_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_scaled_accel  (0x80,0x04) Scaled Accel [C]
/// 3-element vector representing the sensed acceleration.
/// This quantity is temperature compensated and expressed in the vehicle frame.
///
///@{

struct mip_sensor_scaled_accel_data
{
    float scaled_accel[3]; ///< (x, y, z)[g]
    
};
void insert_mip_sensor_scaled_accel_data(struct mip_serializer* serializer, const struct mip_sensor_scaled_accel_data* self);
void extract_mip_sensor_scaled_accel_data(struct mip_serializer* serializer, struct mip_sensor_scaled_accel_data* self);
bool extract_mip_sensor_scaled_accel_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_scaled_gyro  (0x80,0x05) Scaled Gyro [C]
/// 3-element vector representing the sensed angular rate.
/// This quantity is temperature compensated and expressed in the vehicle frame.
///
///@{

struct mip_sensor_scaled_gyro_data
{
    float scaled_gyro[3]; ///< (x, y, z) [radians/second]
    
};
void insert_mip_sensor_scaled_gyro_data(struct mip_serializer* serializer, const struct mip_sensor_scaled_gyro_data* self);
void extract_mip_sensor_scaled_gyro_data(struct mip_serializer* serializer, struct mip_sensor_scaled_gyro_data* self);
bool extract_mip_sensor_scaled_gyro_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_scaled_mag  (0x80,0x06) Scaled Mag [C]
/// 3-element vector representing the sensed magnetic field.
/// This quantity is temperature compensated and expressed in the vehicle frame.
///
///@{

struct mip_sensor_scaled_mag_data
{
    float scaled_mag[3]; ///< (x, y, z) [Gauss]
    
};
void insert_mip_sensor_scaled_mag_data(struct mip_serializer* serializer, const struct mip_sensor_scaled_mag_data* self);
void extract_mip_sensor_scaled_mag_data(struct mip_serializer* serializer, struct mip_sensor_scaled_mag_data* self);
bool extract_mip_sensor_scaled_mag_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_scaled_pressure  (0x80,0x17) Scaled Pressure [C]
/// Scalar value representing the sensed ambient pressure.
///
///@{

struct mip_sensor_scaled_pressure_data
{
    float scaled_pressure; ///< [mBar]
    
};
void insert_mip_sensor_scaled_pressure_data(struct mip_serializer* serializer, const struct mip_sensor_scaled_pressure_data* self);
void extract_mip_sensor_scaled_pressure_data(struct mip_serializer* serializer, struct mip_sensor_scaled_pressure_data* self);
bool extract_mip_sensor_scaled_pressure_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_delta_theta  (0x80,0x07) Delta Theta [C]
/// 3-element vector representing the time integral of angular rate.
/// This quantity is the integral of sensed angular rate over the period set by the IMU message format.  It is expressed in the vehicle frame.
///
///@{

struct mip_sensor_delta_theta_data
{
    float delta_theta[3]; ///< (x, y, z) [radians]
    
};
void insert_mip_sensor_delta_theta_data(struct mip_serializer* serializer, const struct mip_sensor_delta_theta_data* self);
void extract_mip_sensor_delta_theta_data(struct mip_serializer* serializer, struct mip_sensor_delta_theta_data* self);
bool extract_mip_sensor_delta_theta_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_delta_velocity  (0x80,0x08) Delta Velocity [C]
/// 3-element vector representing the time integral of acceleration.
/// This quantity is the integral of sensed acceleration over the period set by the IMU message format.  It is expressed in the vehicle frame.
///
///@{

struct mip_sensor_delta_velocity_data
{
    float delta_velocity[3]; ///< (x, y, z) [g*sec]
    
};
void insert_mip_sensor_delta_velocity_data(struct mip_serializer* serializer, const struct mip_sensor_delta_velocity_data* self);
void extract_mip_sensor_delta_velocity_data(struct mip_serializer* serializer, struct mip_sensor_delta_velocity_data* self);
bool extract_mip_sensor_delta_velocity_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_comp_orientation_matrix  (0x80,0x09) Comp Orientation Matrix [C]
/// 3x3 Direction Cosine Matrix EQSTART M_{ned}^{veh} EQEND describing the orientation of the device with respect to the NED local-level frame.
/// This matrix satisfies the following relationship:
/// 
/// EQSTART v^{veh} = M_{ned}^{veh} v^{ned} EQEND<br/>
/// 
/// Where:<br/>
/// 
/// EQSTART v^{ned} EQEND is a 3-element vector expressed in the NED frame. <br/>
/// EQSTART v^{veh} EQEND is the same 3-element vector expressed in the vehicle frame.  <br/>
/// <br/>
/// The matrix elements are stored is row-major order: EQSTART M = \begin{bmatrix} M_{11}, M_{12}, M_{13}, M_{21}, M_{22}, M_{23}, M_{31}, M_{32}, M_{33} \end{bmatrix} EQEND
///
///@{

struct mip_sensor_comp_orientation_matrix_data
{
    float m[9]; ///< Matrix elements in row-major order.
    
};
void insert_mip_sensor_comp_orientation_matrix_data(struct mip_serializer* serializer, const struct mip_sensor_comp_orientation_matrix_data* self);
void extract_mip_sensor_comp_orientation_matrix_data(struct mip_serializer* serializer, struct mip_sensor_comp_orientation_matrix_data* self);
bool extract_mip_sensor_comp_orientation_matrix_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_comp_quaternion  (0x80,0x0A) Comp Quaternion [C]
/// 4x1 vector representation of the quaternion describing the orientation of the device with respect to the NED local-level frame.
/// This quaternion satisfies the following relationship:
/// 
/// EQSTART p^{veh} = q^{-1} p^{ned} q EQEND<br/>
/// 
/// Where:<br/>
/// EQSTART q = (q_w, q_x, q_y, q_z) ENDEQ is the quaternion desrcribing the rotation. <br/>
/// EQSTART p^ned = (0, v^{ned}_x, v^{ned}_y, v^{ned}_z) ENDEQ and EQSTART v^{ned} EQEND is a 3-element vector expressed in the NED frame.<br/>
/// EQSTART p^veh = (0, v^{veh}_x, v^{veh}_y, v^{veh}_z) ENDEQ and EQSTART v^{veh} EQEND is a 3-element vector expressed in the vehicle frame.<br/>
///
///@{

struct mip_sensor_comp_quaternion_data
{
    float q[4]; ///< Quaternion elements EQSTART q = (q_w, q_x, q_y, q_z) EQEND
    
};
void insert_mip_sensor_comp_quaternion_data(struct mip_serializer* serializer, const struct mip_sensor_comp_quaternion_data* self);
void extract_mip_sensor_comp_quaternion_data(struct mip_serializer* serializer, struct mip_sensor_comp_quaternion_data* self);
bool extract_mip_sensor_comp_quaternion_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_comp_euler_angles  (0x80,0x0C) Comp Euler Angles [C]
/// Euler angles describing the orientation of the device with respect to the NED local-level frame.
/// The Euler angles are reported in 3-2-1 (Yaw-Pitch-Roll, AKA Aircraft) order.
///
///@{

struct mip_sensor_comp_euler_angles_data
{
    float roll; ///< [radians]
    float pitch; ///< [radians]
    float yaw; ///< [radians]
    
};
void insert_mip_sensor_comp_euler_angles_data(struct mip_serializer* serializer, const struct mip_sensor_comp_euler_angles_data* self);
void extract_mip_sensor_comp_euler_angles_data(struct mip_serializer* serializer, struct mip_sensor_comp_euler_angles_data* self);
bool extract_mip_sensor_comp_euler_angles_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_comp_orientation_update_matrix  (0x80,0x0B) Comp Orientation Update Matrix [C]
/// DEPRECATED!
///
///@{

struct mip_sensor_comp_orientation_update_matrix_data
{
    float m[9];
    
};
void insert_mip_sensor_comp_orientation_update_matrix_data(struct mip_serializer* serializer, const struct mip_sensor_comp_orientation_update_matrix_data* self);
void extract_mip_sensor_comp_orientation_update_matrix_data(struct mip_serializer* serializer, struct mip_sensor_comp_orientation_update_matrix_data* self);
bool extract_mip_sensor_comp_orientation_update_matrix_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_orientation_raw_temp  (0x80,0x0D) Orientation Raw Temp [C]
/// DEPRECATED!
///
///@{

struct mip_sensor_orientation_raw_temp_data
{
    uint16_t raw_temp[4];
    
};
void insert_mip_sensor_orientation_raw_temp_data(struct mip_serializer* serializer, const struct mip_sensor_orientation_raw_temp_data* self);
void extract_mip_sensor_orientation_raw_temp_data(struct mip_serializer* serializer, struct mip_sensor_orientation_raw_temp_data* self);
bool extract_mip_sensor_orientation_raw_temp_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_internal_timestamp  (0x80,0x0E) Internal Timestamp [C]
/// DEPRECATED!
///
///@{

struct mip_sensor_internal_timestamp_data
{
    uint32_t counts;
    
};
void insert_mip_sensor_internal_timestamp_data(struct mip_serializer* serializer, const struct mip_sensor_internal_timestamp_data* self);
void extract_mip_sensor_internal_timestamp_data(struct mip_serializer* serializer, struct mip_sensor_internal_timestamp_data* self);
bool extract_mip_sensor_internal_timestamp_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_pps_timestamp  (0x80,0x0F) Pps Timestamp [C]
/// DEPRECATED!
///
///@{

struct mip_sensor_pps_timestamp_data
{
    uint32_t seconds;
    uint32_t useconds;
    
};
void insert_mip_sensor_pps_timestamp_data(struct mip_serializer* serializer, const struct mip_sensor_pps_timestamp_data* self);
void extract_mip_sensor_pps_timestamp_data(struct mip_serializer* serializer, struct mip_sensor_pps_timestamp_data* self);
bool extract_mip_sensor_pps_timestamp_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_gps_timestamp  (0x80,0x12) Gps Timestamp [C]
/// GPS timestamp of the SENSOR data
/// 
/// Should the PPS become unavailable, the device will revert to its internal clock, which will cause the reported time to drift from true GPS time.
/// Upon recovering from a PPS outage, the user should expect a jump in the reported GPS time due to the accumulation of internal clock error.
/// If synchronization to an external clock or onboard GNSS receiver (for products that have one) is disabled, this time is equivalent to internal system time.
/// 
/// Note: this data field may be deprecrated in the future. The more flexible shared data field (0x80, 0xD3) should be used instead.
///
///@{

enum mip_sensor_gps_timestamp_data_valid_flags
{
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_NONE              = 0x0000,
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_PPS_VALID         = 0x0001,
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_TIME_REFRESH      = 0x0002,
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_TIME_INITIALIZED  = 0x0004,
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_TOW_VALID         = 0x0008,
    MIP_SENSOR_GPS_TIMESTAMP_DATA_VALID_FLAGS_WEEK_NUMBER_VALID = 0x0010,
};

struct mip_sensor_gps_timestamp_data
{
    double tow; ///< GPS Time of Week [seconds]
    uint16_t week_number; ///< GPS Week Number since 1980 [weeks]
    enum mip_sensor_gps_timestamp_data_valid_flags valid_flags;
    
};
void insert_mip_sensor_gps_timestamp_data(struct mip_serializer* serializer, const struct mip_sensor_gps_timestamp_data* self);
void extract_mip_sensor_gps_timestamp_data(struct mip_serializer* serializer, struct mip_sensor_gps_timestamp_data* self);
bool extract_mip_sensor_gps_timestamp_data_from_field(const struct mip_field* field, void* ptr);

void insert_mip_sensor_gps_timestamp_data_valid_flags(struct mip_serializer* serializer, const enum mip_sensor_gps_timestamp_data_valid_flags self);
void extract_mip_sensor_gps_timestamp_data_valid_flags(struct mip_serializer* serializer, enum mip_sensor_gps_timestamp_data_valid_flags* self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_temperature_abs  (0x80,0x14) Temperature Abs [C]
/// SENSOR reported temperature statistics
/// 
/// Temperature may originate from the MEMS sensors, or be calculated in combination with board temperature sensors.
/// All quantities are calculated with respect to the last power on or reset, whichever is later.
/// 
///
///@{

struct mip_sensor_temperature_abs_data
{
    float min_temp; ///< [degC]
    float max_temp; ///< [degC]
    float mean_temp; ///< [degC]
    
};
void insert_mip_sensor_temperature_abs_data(struct mip_serializer* serializer, const struct mip_sensor_temperature_abs_data* self);
void extract_mip_sensor_temperature_abs_data(struct mip_serializer* serializer, struct mip_sensor_temperature_abs_data* self);
bool extract_mip_sensor_temperature_abs_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_up_vector  (0x80,0x11) Up Vector [C]
/// Gyro-stabilized 3-element vector representing the complementary filter's estimated vertical direction.
/// This quantity is expressed in the vehicle frame.
/// 
/// This quantity is sensitive to non-gravitational accelerations, which may cause notable deviations from the true vertical direction.
/// 
/// For legacy reasons, this vector is the inverse of the gravity vector.
/// 
///
///@{

struct mip_sensor_up_vector_data
{
    float up[3]; ///< [Gs]
    
};
void insert_mip_sensor_up_vector_data(struct mip_serializer* serializer, const struct mip_sensor_up_vector_data* self);
void extract_mip_sensor_up_vector_data(struct mip_serializer* serializer, struct mip_sensor_up_vector_data* self);
bool extract_mip_sensor_up_vector_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_north_vector  (0x80,0x10) North Vector [C]
/// Gyro-stabilized 3-element vector representing the complementary filter's estimate of magnetic north.
/// This quantity is expressed in the vehicle frame.
/// 
/// This quantity is sensitive to local magnetic field perturbations, which may cause notable deviations from true magnetic north.
///
///@{

struct mip_sensor_north_vector_data
{
    float north[3]; ///< [Gauss]
    
};
void insert_mip_sensor_north_vector_data(struct mip_serializer* serializer, const struct mip_sensor_north_vector_data* self);
void extract_mip_sensor_north_vector_data(struct mip_serializer* serializer, struct mip_sensor_north_vector_data* self);
bool extract_mip_sensor_north_vector_data_from_field(const struct mip_field* field, void* ptr);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_overrange_status  (0x80,0x18) Overrange Status [C]
///
///@{

enum mip_sensor_overrange_status_data_status
{
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_NONE    = 0x0000,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_ACCEL_X = 0x0001,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_ACCEL_Y = 0x0002,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_ACCEL_Z = 0x0004,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_GYRO_X  = 0x0010,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_GYRO_Y  = 0x0020,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_GYRO_Z  = 0x0040,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_MAG_X   = 0x0100,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_MAG_Y   = 0x0200,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_MAG_Z   = 0x0400,
    MIP_SENSOR_OVERRANGE_STATUS_DATA_STATUS_PRESS   = 0x1000,
};

struct mip_sensor_overrange_status_data
{
    enum mip_sensor_overrange_status_data_status status;
    
};
void insert_mip_sensor_overrange_status_data(struct mip_serializer* serializer, const struct mip_sensor_overrange_status_data* self);
void extract_mip_sensor_overrange_status_data(struct mip_serializer* serializer, struct mip_sensor_overrange_status_data* self);
bool extract_mip_sensor_overrange_status_data_from_field(const struct mip_field* field, void* ptr);

void insert_mip_sensor_overrange_status_data_status(struct mip_serializer* serializer, const enum mip_sensor_overrange_status_data_status self);
void extract_mip_sensor_overrange_status_data_status(struct mip_serializer* serializer, enum mip_sensor_overrange_status_data_status* self);

///@}
///
////////////////////////////////////////////////////////////////////////////////
///@defgroup c_sensor_odometer_data  (0x80,0x40) Odometer Data [C]
///
///@{

struct mip_sensor_odometer_data_data
{
    float speed; ///< Average speed over the time interval [m/s]. Can be negative for quadrature encoders.
    float uncertainty; ///< Uncertainty of velocity [m/s].
    uint16_t valid_flags; ///< If odometer is configured, bit 0 will be set to 1.
    
};
void insert_mip_sensor_odometer_data_data(struct mip_serializer* serializer, const struct mip_sensor_odometer_data_data* self);
void extract_mip_sensor_odometer_data_data(struct mip_serializer* serializer, struct mip_sensor_odometer_data_data* self);
bool extract_mip_sensor_odometer_data_data_from_field(const struct mip_field* field, void* ptr);

///@}
///

///@}
///@}
///
////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
} // namespace C
} // namespace mip
} // extern "C"
#endif // __cplusplus

