
$fn = 32;
wormgear_rotateXZoYgear_fn = $fn;

use <Thread_Library.scad>
use <involute_gears.scad>

shell_width = 170;
shell_length = 170;
shell_height = 170;
shell_wall_thickness = 10;
shell_bottom = 10;/*dno*/
shell_bottom_ballbear_outer = 40;
shell_bottom_ballbear_inner = 20;
shell_bottom_ballbear_height = 5;
mainshaft_length = 200;
mainshaft_diameter = shell_bottom_ballbear_inner;
stepmotor_width = 35;
stepmotor_length = 35;
stepmotor_height = 34;
stepmotor_shaft_length = 24;
stepmotor_shaft_diameter = 3.5;
stepmotors_plate_diameter = 148;

module shell()
{
  color( [ 0.1, 0.4, 0.8 ] )
  difference()
  {
    translate( [ 0, 0, shell_height / 2 ] )
      cube( [ shell_width, shell_length, shell_height ], center = true );
    translate( [ 0, 0, shell_bottom ] )
      translate( [ 0, 0, shell_height / 2 ] )
        cube( [ shell_width - 2 * shell_wall_thickness, shell_length - 2 * shell_wall_thickness, shell_height ], center = true );
    hull()
    {
      shell_bottom_ballbear();
    }
    stepmotor_rotate_base();
  }
  difference()
  {
    translate( [ 0, 0, shell_bottom ] )
      translate( [ -(shell_width - 2 * shell_wall_thickness ) / 2, -(shell_length - 2 * shell_wall_thickness ) / 2, 0 ] )
      cube( [ shell_width - 2 * shell_wall_thickness, shell_length - 2 * shell_wall_thickness, 35 ] );
    flange_thickness = 8;
    translate( [ 0, 0, shell_bottom ] )
      translate( [ -(shell_width - 2 * shell_wall_thickness ) / 2 + flange_thickness, -(shell_length - 2 * shell_wall_thickness ) / 2 + flange_thickness, 0 ] )
      cube( [ shell_width - 2 * shell_wall_thickness - 2 * flange_thickness, shell_length - 2 * shell_wall_thickness - 2 * flange_thickness, 35 + 0.01 ] );
  }
  difference()
  {
    translate( [ 0, 0, shell_bottom ] )
      translate( [ -(shell_width - 2 * shell_wall_thickness ) / 2, -(shell_length - 2 * shell_wall_thickness ) / 2, 40 ] )
      cube( [ shell_width - 2 * shell_wall_thickness, shell_length - 2 * shell_wall_thickness, 30 ] );
    flange_thickness = 4;
    translate( [ 0, 0, shell_bottom ] )
      translate( [ -(shell_width - 2 * shell_wall_thickness ) / 2 + flange_thickness, -(shell_length - 2 * shell_wall_thickness ) / 2 + flange_thickness, 40 ] )
      cube( [ shell_width - 2 * shell_wall_thickness - 2 * flange_thickness, shell_length - 2 * shell_wall_thickness - 2 * flange_thickness, 30 + 0.01 ] );
  }
}
//shell();
module stepmotor()
{
  color( [ 0.11, 0.38, 0.4 ] )
  union()
  {
    translate( [ 0, 0, stepmotor_height / 2 ] )
    {
      cube( [ stepmotor_width, stepmotor_length, stepmotor_height ], center = true );
      translate( [ 0, 0, stepmotor_height / 2 ] )
        cylinder( r = 3, h = stepmotor_shaft_length );
    }
  }
}

module stepmotor_rotate_base()
{
    union()
    {
        offset_z = 3;
        translate( [ 27 + stepmotor_width / 2, 67, shell_bottom - offset_z ] )
          translate( [ 0, 0, stepmotor_height / 2 ] )
            rotate( 90, [ 1, 0, 0 ] )        
              stepmotor();
    }
}

module ballbear( outter_diameter, inner_diameter, height )
{
  offset = 0.01;
  color( [ 0.3, 0.3, 0.3 ] )
  difference()
  {
    translate( [ 0, 0, offset ] )
    {
      cylinder( r = outter_diameter / 2, height );
    }
    cylinder( r = inner_diameter / 2, height + 2 * offset );
  }
}
//ballbear( 20, 10, 5 );
module shell_bottom_ballbear()
{
  translate( [ 0, 0, shell_bottom - shell_bottom_ballbear_height ] )
    ballbear( shell_bottom_ballbear_outer, shell_bottom_ballbear_inner, shell_bottom_ballbear_height );
}

module main_shaft()
{
    color( [ 0.7, 0.1, 0.9 ] )
    translate( [ 0, 0, shell_bottom - shell_bottom_ballbear_height ] )
      cylinder( r = mainshaft_diameter / 2, h = mainshaft_length );
}


module plane_cut()
{
    translate( [ 0, 0, -0.1 ] )
    rotate( 90, [ 0, 0, 1 ] )
      cube( [ 300, 300, 300 ] );
}

module wormgear_rotateXZoYgear()
{
    difference()
    {
        union()
        {
            numberTeeth=24;
            pitchRadius=35;


            length=55;
            radius=8;
            pitch=2*3.1416*pitchRadius/numberTeeth;

            angle=-360*$t;
            offset=-2.5;

            distance=radius+pitchRadius+0.0*pitch;

            translate([0,15,0])
            {
                translate([0,0,-length/2])
                rotate([0,0,180+angle])
                trapezoidThread( 
                    length=length, 			// axial length of the threaded rod
                    pitch=pitch,				 // axial distance from crest to crest
                    pitchRadius=radius, 		// radial distance from center to mid-profile
                    threadHeightToPitch=0.5, 	// ratio between the height of the profile and the pitch
                                        // std value for Acme or metric lead screw is 0.5
                    profileRatio=0.5,			 // ratio between the lengths of the raised part of the profile and the pitch
                                        // std value for Acme or metric lead screw is 0.5
                    threadAngle=20, 			// angle between the two faces of the thread
                                        // std value for Acme is 29 or for metric lead screw is 30
                    RH=true, 				// true/false the thread winds clockwise looking along shaft, i.e.follows the Right Hand Rule
                    clearance=0.1, 			// radial clearance, normalized to thread height
                    backlash=0.1, 			// axial clearance, normalized to pitch
                    stepsPerTurn=wormgear_rotateXZoYgear_fn 			// number of slices to create per turn
                    );


                translate([-5,-distance,0])
                rotate([0,90,0])
                rotate([0,0,offset-angle/numberTeeth+1.7])
                gear ( 
                    number_of_teeth=numberTeeth,
                    circular_pitch=360*pitchRadius/numberTeeth,
                    pressure_angle=20,
                    clearance = 0,
                    gear_thickness=5,
                    rim_thickness=5,
                    rim_width=5,
                    hub_thickness=10,
                    hub_diameter=10,
                    bore_diameter=5,
                    circles=0,
                    backlash=-0.9,
                    twist=-2,
                    involute_facets=0,
                    flat=false);
            }
        }
    }
}

module separator_plate()
{
    difference()
    {
      translate( [ -( shell_width - 2 * shell_wall_thickness ) / 2, -( shell_length - 2 * shell_wall_thickness ) / 2, shell_bottom + 35 ] )
        cube( [ shell_width - 2 * shell_wall_thickness, shell_length - 2 * shell_wall_thickness, 5 ] );
        hull()
        {
          separator_plate_ballbear();
        }
    }
}

module separator_plate_ballbear()
{
  translate( [ 0, 0, shell_bottom + 35 - 0.02 ] )
    ballbear( shell_bottom_ballbear_outer, shell_bottom_ballbear_inner, shell_bottom_ballbear_height + 0.2 );
}

module stepmotors_plate()
{
  color( [ 0.7, 0.3, 0.1 ] )
  difference()
  {
    translate( [ 0, 0, 80 ] )
      cylinder( r = stepmotors_plate_diameter / 2, h = 10 );
    main_shaft();
    stepmotor_legs();
  }
}
stepmotors_plate();
module stepmotor_leg_1()
{
  union()
  {
    translate( [ 0, 35, 90 ] )
      stepmotor();
  }
}

module stepmotor_legs()
{
  motor_count = 6;
  union()
  {
    for( i = [ 0 : motor_count ] )
    {
      offsetZ = 2;
      rotate( 360 / motor_count * i, [ 0, 0, 1 ] )
        translate( [ 0, 45, 90 - offsetZ ] )
        rotate( 45, [ 0, 0, 1 ] )
          stepmotor();
    }
  }
}
//stepmotor_leg_1();

module all_together()
{
    difference()
    {
        union()
        {
            shell();
            stepmotor_rotate_base();
            shell_bottom_ballbear();
            difference()
            {
                offset_z = 3;
                translate( [ 29.5, 0, 0 ] )
                translate( [ 0, 0, 27 - offset_z ] )
                rotate( 90, [ 1, 0, 0 ] )
                rotate( -90, [ 0, 0, 1 ] )
                wormgear_rotateXZoYgear();
                main_shaft();
            }
            main_shaft();
            separator_plate();
            separator_plate_ballbear();
            stepmotors_plate();
            stepmotor_legs();
        }
        plane_cut();
    }
}
//render()
all_together();
*difference()
{
    translate( [ 29.5, 0, 0 ] )
    translate( [ 0, 0, 27 ] )
    rotate( 90, [ 1, 0, 0 ] )
    rotate( -90, [ 0, 0, 1 ] )
    wormgear_rotateXZoYgear();
    main_shaft();
    stepmotor_rotate_base();
}