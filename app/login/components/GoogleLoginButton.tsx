"use client";

import { supabase } from "@/lib/supabaseClient";

export async function signInWithGoogle() {
  const { data, error } = await supabase.auth.signInWithOAuth({
    provider: "google",
    options: {
      redirectTo: `${location.origin}/auth/callback`,
    },
  });
  if (error) throw error;
  return data;
}
