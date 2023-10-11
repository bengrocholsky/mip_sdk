
#include "example_utils.hpp"

#include <mip/definitions/commands_base.hpp>
#include <mip/definitions/commands_filter.hpp>
#include <mip/definitions/commands_3dm.hpp>

#include <stdexcept>
#include <vector>
#include <cstring>
#include <stdio.h>


int main(int argc, const char* argv[])
{
  std::unique_ptr<ExampleUtils> utils;
  try
    {
      utils = handleCommonArgs(argc, argv);
    }
  catch(const std::exception& ex)
    {
      fprintf(stderr, "Error: %s\n", ex.what());
      return 1;
    }
  std::unique_ptr<mip::DeviceInterface>& device = utils->device;;

  
  mip::commands_base::BaseDeviceInfo device_info;
  try
    {
	//
	//Idle the device (note: this is good to do during setup)
	//
	if(mip::commands_base::setIdle(*device) != mip::CmdResult::ACK_OK)
	  {
	    printf("ERROR: Could not set the device to idle!");
	    exit(0);
	  }

	//
	//Load the device default settings (so the device is in a known state)
	//
	// does this overwite CAL values?
	/*
	  if(mip::commands_3dm::defaultDeviceSettings(*device) != mip::CmdResult::ACK_OK)
	  {
	    printf("ERROR: Could not load default device settings!");
	    exit(0);
	  }
	*/
    }
  catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }

  mip::CmdResult result;
  float offset[3] = {0};
  try
    {
      result = mip::commands_3dm::readMagHardIronOffset(*device, offset);
      if( result == mip::CmdResult::ACK_OK)
	{
	  printf("Success reading MagHardIron offset:\n");
	  for (size_t i=0;i<3;i++)
	    printf("%f ", offset[i]);
	  printf("\n");
	}
      else
	printf("Error reading MagHardIron offset:\n");
    }
  catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }

  float matrix[9] = {0};
  try
    {
      mip::CmdResult result = mip::commands_3dm::readMagSoftIronMatrix(*device, matrix);
      if( result == mip::CmdResult::ACK_OK)
	{
	  printf("Success reading MagSoftIron matrix:\n");
	  for (size_t i=0;i<9;i++)
	    printf("%f ", matrix[i]);
	  printf("\n");
	}
      else
	printf("Error reading MagSoftIron offset:\n");
    }
  catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }

  
  offset[0] = -0.0132;
  offset[1] = 0.0091;
  offset[2] = -0.0154;
  matrix[0]=1.0168;
  matrix[4]=0.9811;
  matrix[8]=1.0002;
  try
    {
      result = mip::commands_3dm::writeMagHardIronOffset(*device, offset);
      if( result == mip::CmdResult::ACK_OK)
	{
	  printf("Success writing MagHardIron offset:\n");
	  for (size_t i=0;i<3;i++)
	    printf("%f ", offset[i]);
	  printf("\n");
	}
      else
	printf("Error writing MagHardIron offset:\n");
      result = mip::commands_3dm::saveMagHardIronOffset(*device);
      if( result == mip::CmdResult::ACK_OK)
	printf("Success saving MagHardIron offset:\n");
      else
	printf("Error saving MagHardIron offset:\n");
    }
  catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }
  try
      {
      result = mip::commands_3dm::writeMagSoftIronMatrix(*device, matrix);
      if( result == mip::CmdResult::ACK_OK)
	{
	  printf("Success writing MagHardIron matrix:\n");
	  for (size_t i=0;i<9;i++)
	    printf("%f ", matrix[i]);
	  printf("\n");
	}
      else
	printf("Error writing MagHardIron matrix:\n");
      result = mip::commands_3dm::saveMagSoftIronMatrix(*device);
      if( result == mip::CmdResult::ACK_OK)
	printf("Success saving MagHardIron matrix:\n");
      else
	printf("Error saving MagHardIron matrix:\n");
    }
  catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }
  
  
  try
    {
      
	result = mip::commands_base::getDeviceInfo(*device, &device_info);

        if( result == mip::CmdResult::ACK_OK)
        {
            printf("Success:\n");

            auto print_info = [](const char* name, const char info[16])
            {
                char msg[17] = {0};
                std::strncpy(msg, info, 16);
                printf("  %s%s\n", name, msg);
            };

            print_info("Model name:       ", device_info.model_name);
            print_info("Model number:     ", device_info.model_number);
            print_info("Serial Number:    ", device_info.serial_number);
            print_info("Device Options:   ", device_info.device_options);
            print_info("Lot Number:       ", device_info.lot_number);

            printf(  "  Firmware version:           %d.%d.%d\n\n",
                (device_info.firmware_version / 1000),
                (device_info.firmware_version / 100) % 10,
                (device_info.firmware_version / 1)   % 100
            );
        }
        else
        {
            printf("Error: command completed with NACK: %s (%d)\n", result.name(), result.value);
        }
    }
    catch(const std::underflow_error& ex)
      {
        return printCommonUsage(argv);
      }
    catch(const std::exception& ex)
    {
        fprintf(stderr, "Error: %s\n", ex.what());
        return 1;
    }
  
  if(mip::commands_base::resume(*device) != mip::CmdResult::ACK_OK)
    {
      printf("ERROR: Could not set the device to resume from idle!");
      exit(0);
    }

    return 0;
}
