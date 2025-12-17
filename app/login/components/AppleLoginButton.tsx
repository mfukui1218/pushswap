"use client";

import { supabase } from "@/lib/supabaseClient";

export async function signInWithApple() {
  const { data, error } = await supabase.auth.signInWithOAuth({
    provider: "apple",
    options: {
      redirectTo: `${location.origin}/auth/callback`,
    },
  });
  if (error) throw error;
  return data;
}
