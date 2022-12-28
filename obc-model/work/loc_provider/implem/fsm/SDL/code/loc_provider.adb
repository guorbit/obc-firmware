-- This file was generated automatically by OpenGEODE: DO NOT MODIFY IT !

with System.IO;
use System.IO;

with Ada.Unchecked_Conversion;
with Ada.Numerics.Generic_Elementary_Functions;

package body Loc_Provider is
   procedure request_loc_Transition is
      begin
         case ctxt.state is
            when asn1Sccwait =>
               Execute_Transition (1);
            when others =>
               Execute_Transition (CS_Only);
         end case;
      end request_loc_Transition;
      

   procedure Execute_Transition (Id : Integer) is
      trId : Integer := Id;
      begin
         while (trId /= -1) loop
            case trId is
               when 0 =>
                  --  k_max := 999 (12,13)
                  ctxt.k_max := 999;
                  --  NEXT_STATE Wait (14,18) at 18, 133
                  trId := -1;
                  ctxt.State := asn1SccWait;
                  goto Continuous_Signals;
               when 1 =>
                  --  k := (k+1) mod (k_max+1) (20,17)
                  ctxt.k := ((ctxt.k + 1) mod (ctxt.k_max + 1));
                  --  NEXT_STATE Wait (22,22) at 129, 344
                  trId := -1;
                  ctxt.State := asn1SccWait;
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
end Loc_Provider;