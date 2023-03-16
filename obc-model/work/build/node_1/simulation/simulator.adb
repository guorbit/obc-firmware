with Text_IO;   use Text_IO;

package body Simulator is
   procedure Push_Event (Event : asn1SccObservable_Event) is
      Next_Pos : constant Integer := Events.Length + 1;
   begin
      if Events.Length < Integer (Max_Events)
      then
         Events.Length := Events.Length + 1;
--        Put_Line ("Storing event at position " & Next_Pos'Img
--                  & " - nb of elements: " & Events.Length'Img);
         Events.Data (Next_Pos) := Event;
      else
         Put_Line ("Event dropped: queue full");
      end if;
   end Push_Event;

   function Pop_Event return asn1SccObservable_Event is
      Result : asn1SccObservable_Event;
   begin
      if Events.Length = 0 then
         raise Empty_Queue;
      end if;
      Result        := Events.Data (1);
      Events.Length := Events.Length - 1;

      for I in 1 .. Events.Length loop
         Events.Data (I) := Events.Data (I + 1);
      end loop;
      --  Reset the slots that were moved, to clean up the global state
      Events.Data (Events.Length + 1 .. Integer (Max_Events)) :=
        (others => asn1SccObservable_Event_Init);

      return Result;
   end Pop_Event;

end Simulator;
