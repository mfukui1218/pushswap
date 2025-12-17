"use client";

import { supabase } from "@/lib/supabaseClient";

export async function loginWithEmailPassword(args: {
  email: string;
  password: string;
}) {
  const email = args.email.trim().toLowerCase();
  const password = args.password;

  const { data, error } = await supabase.auth.signInWithPassword({
    email,
    password,
  });

  if (!error) {
    const loginEmail = data.user?.email?.toLowerCase().trim() ?? "";
    if (!loginEmail) throw new Error("メールアドレスを取得できませんでした。");
    return;
  }

  const msg = (error.message || "").toLowerCase();

  if (msg.includes("invalid login credentials")) {
    throw new Error("メールアドレスまたはパスワードが違います。");
  }
  if (msg.includes("email not confirmed")) {
    throw new Error("メール確認が完了していません。受信メールを確認してください。");
  }
  if (msg.includes("invalid email")) {
    throw new Error("メールアドレスの形式が正しくありません。");
  }

  throw new Error("ログインに失敗しました。");
}
