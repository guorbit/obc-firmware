-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Payload_Subsystem is
   procedure Trigger_capture is
      begin
         case ctxt.state is
            when asn1Sccimaging =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end Trigger_capture;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  NEXT_STATE Imaging (6,18) at 319, 60
                  trId := -1;
                  ctxt.State := asn1SccImaging;
                  goto Continuous_Signals;
               when 1 =>
                  --  writeln("picture taken!") (12,17)
                  Put ("picture taken!");
                  New_Line;
                  --  NEXT_STATE Imaging (14,22) at 578, 223
                  trId := -1;
                  ctxt.State := asn1SccImaging;
                  goto Continuous_Signals;
               when CS_Only =>
                  trId := -1;
                  goto Continuous_Signals;
               when others =>
                  null;
            end case;
            <<Continuous_Signals>>
            <<Next_Transition>>
         end loop;
      end Execute_Transition;
      

   procedure Startup is
      begin
         Execute_Transition (0);
         ctxt.Init_Done := True;
      end Startup;
   begin
      Startup;
end Payload_Subsystem;