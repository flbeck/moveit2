/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Dave Coleman */

#pragma once

// SA
#include <moveit_setup_framework/qt/setup_step_widget.hpp>
#include <moveit_setup_framework/qt/double_list_widget.hpp>
#include <moveit_setup_srdf_plugins/passive_joints.hpp>

namespace moveit_setup_srdf_plugins
{
class PassiveJointsWidget : public moveit_setup_framework::SetupStepWidget
{
  Q_OBJECT

public:
  // ******************************************************************************************
  // Public Functions
  // ******************************************************************************************

  void onInit() override;

  /// Received when this widget is chosen from the navigation menu
  void focusGiven() override;

  moveit_setup_framework::SetupStep& getSetupStep() override
  {
    return setup_step_;
  }

  // ******************************************************************************************
  // Qt Components
  // ******************************************************************************************

  moveit_setup_framework::DoubleListWidget* joints_widget_;

private Q_SLOTS:

  // ******************************************************************************************
  // Slot Event Functions
  // ******************************************************************************************
  void selectionUpdated();

  /// Called from Double List widget to highlight joints
  void previewSelectedJoints(const std::vector<std::string>& joints);

private:
  // ******************************************************************************************
  // Variables
  // ******************************************************************************************

  PassiveJoints setup_step_;

  /// Original name of vjoint currently being edited. This is used to find the element in the vector
  std::string current_edit_vjoint_;
};

}  // namespace moveit_setup_srdf_plugins
